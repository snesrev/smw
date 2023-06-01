# pip install zstandard
import zstandard
dict_data = zstandard.ZstdCompressionDict(open('smas.sfc', 'rb').read())
cctx = zstandard.ZstdDecompressor(dict_data=dict_data)
with open('smb1.zst', 'rb') as ifp:
    with open('smb1.sfc', 'wb') as ofp:
        ofp.write(cctx.decompress(ifp.read()))
