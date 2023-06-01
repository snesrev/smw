# pip install zstandard
import zstandard
import hashlib

SHA1_HASH = 'c05817c5b7df2fbfe631563e0b37237156a8f6b6'
smas = open('smas.sfc', 'rb').read()
hash = hashlib.sha1(smas).hexdigest()
if hash != SHA1_HASH:
  raise Exception('You need SMAS with sha1 ' + SHA1_HASH + ' yours is ' + hash)
dict_data = zstandard.ZstdCompressionDict(smas)
cctx = zstandard.ZstdDecompressor(dict_data=dict_data)
with open('smb1.zst', 'rb') as ifp:
    with open('smb1.sfc', 'wb') as ofp:
        ofp.write(cctx.decompress(ifp.read()))
