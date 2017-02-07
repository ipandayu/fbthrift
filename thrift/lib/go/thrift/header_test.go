package thrift

import (
	"bufio"
	"bytes"
	"encoding/hex"
	"io/ioutil"
	"testing"
)

func MustDecodeHex(s string) []byte {
	res, err := hex.DecodeString(s)
	if err != nil {
		panic(err)
	}
	return res
}

var GetStatusCall = MustDecodeHex(
	"0000001c0fff0000000000000001020000008222000967657453746174757300",
)
var GetStatusCallData = MustDecodeHex(
	"8222000967657453746174757300",
)

var GetStatusReply = MustDecodeHex(
	"0000001f0fff0000000000000001020000008242000967657453746174757305000400",
)

var GetStatusReplyData = MustDecodeHex("8242000967657453746174757305000400")

func TestHeaderRead(t *testing.T) {

	tmb := NewTMemoryBuffer()
	tht := NewTHeaderTransport(tmb)

	_, err := tht.Write(GetStatusCall)
	if err != nil {
		t.Fatalf("failed to write call: %s", err.Error())
	}

	err = tht.Flush()
	if err != nil {
		t.Fatalf("failed to flush: %s", err.Error())
	}

	err = tht.ResetProtocol()
	if err != nil {
		t.Fatalf("failed to read frame: %s", err.Error())
	}

	out, err := ioutil.ReadAll(tht)
	if err != nil {
		t.Fatalf("failed to read tmb: %s", err.Error())
	}
	assertEq(t, 32, len(out))
}

func TestHeaderDeserSer(t *testing.T) {

	buf := bufio.NewReader(bytes.NewBuffer(GetStatusCall))
	hdr := &tHeader{}
	err := hdr.Read(buf)

	if err != nil {
		t.Fatalf("failed to parse correct header: %s", err.Error())
	}

	if hdr.protoID != CompactProtocol {
		t.Errorf("expected compact proto, got: %#x", int64(hdr.protoID))
	}

	if hdr.protoID != CompactProtocol {
		t.Errorf("expected compact proto, got: %#x", int64(hdr.protoID))
	}

	wbuf := bytes.NewBuffer(nil)
	err = hdr.Write(wbuf)

	if err != nil {
		t.Fatalf("failed to write correct header: %s", err.Error())
	}

}

func assertEq(t *testing.T, expected interface{}, actual interface{}) {
	if expected != actual {
		t.Errorf("assertEq failed: actual=%+v expected=%+v", actual, expected)
	}
}
