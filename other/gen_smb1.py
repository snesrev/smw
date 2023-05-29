import zstandard
dict_data = zstandard.ZstdCompressionDict(open('smas.sfc', 'rb').read())

cctx = zstandard.ZstdCompressor(dict_data=dict_data, level=12)
with open('smb1.sfc', 'rb') as ifp:
    with open('smb1.zst', 'wb') as ofp:
        ofp.write(cctx.compress(ifp.read()))
