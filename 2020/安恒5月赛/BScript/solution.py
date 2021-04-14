import base64
from hashlib import md5
target=b'QkpEe1doT3RfNF9iYWV1dDFmdTFfc2NybHB0fQAA'
flag=base64.b64decode(target)
# print(flag)
# BJD{WhOt_4_baeut1fu1_scrlpt}
m = md5()
m.update(flag[:-2])
print(m.hexdigest())
# e801bcbcc42d3120d910ccc46ae640dd