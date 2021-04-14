import zipfile
import os
def ext():
	path='./0573'
	folder_abs='./0573'
	find=False
	while not find:
		for r,d,f in os.walk(path):
			print(f)
			for file in f:
				if '.zip' in file:
					zip_file = zipfile.ZipFile(r+'/'+file)
					zip_list = zip_file.namelist() # 得到压缩包里所有文件
					for f in zip_list:
						zip_file.extract(f, folder_abs,pwd=file[:4].encode('utf-8')) # 循环解压文件到指定目录
					zip_file.close()
					os.remove(r+'/'+file)
				else:
					find=True

ext()