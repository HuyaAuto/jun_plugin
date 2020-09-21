package com.opensource.nredis.proxy.monitor.file.utils;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.io.UnsupportedEncodingException;
import java.net.URL;
import java.net.URLDecoder;
/**
 * 文件工具类
 * @author liubing
 *
 */
public class FileUtil {
	
	
	/**
	 * 从系统路径读取文件内容
	 * 
	 * @param FilePath
	 * @return
	 * @throws IOException
	 */
	public static byte[] loadFileFromSysPath(String filePath) {
		byte[] fileContent = null;
		fileContent = loadFile(new File(filePath));
		return fileContent;
	}

	/**
	 * 从系统路径读取文件内容
	 * 
	 * @param FilePath
	 * @return
	 * @throws IOException
	 */
	public static byte[] loadFileFromSysPath(String filePath, int beginPos, int endPos) {
		byte[] fileContent = null;
		fileContent = loadFile(new File(filePath), beginPos, endPos);
		return fileContent;
	}

	/**
	 * 从应用的工作根目录为根的相对路径读取文件内容
	 * 
	 * @param FilePath
	 * @return
	 * @throws IOException
	 */
	public static byte[] loadFileFromContextPath(String filePath, int beginPos, int endPos) {
		String spliter = filePath.startsWith(File.separator) == true ? "" : File.separator;
		String fullFilePath = EnvUtil.getContextPath() + spliter + filePath;
		return loadFileFromSysPath(fullFilePath, beginPos, endPos);
	}

	/**
	 * 获取应用的工作根目录为根的相对路径
	 * 
	 * @param FilePath
	 * @return
	 * @throws IOException
	 */
	public static byte[] loadFileFromContextPath(String filePath) {
		String spliter = filePath.startsWith(File.separator) == true ? "" : File.separator;
		String fullFilePath = EnvUtil.getContextPath() + spliter + filePath;
		return loadFileFromSysPath(fullFilePath);
	}

	/**
	 * 读取在Context的资源文件 完整路径
	 * 
	 * @param resourcePath
	 *            路径起始不带"/"
	 * @return
	 * @throws IOException
	 */
	public static File getResourceFile(String resourcePath) {
		try {
			resourcePath = URLDecoder.decode(resourcePath,"utf-8");
			URL url = EnvUtil.class.getClassLoader().getResource(resourcePath);
			if(url!=null){
				File file = new File(url.getFile());
				return file;
			}
			return null;
		} catch (UnsupportedEncodingException e) {	
			//Logger.error(e);
			return null;
		}  
		
	}

	/**
	 * 读取在Context的资源文件 完整路径
	 * 
	 * @param resourcePath
	 *            路径起始不带"/"
	 * @return
	 * @throws IOException
	 */
	public static byte[] loadResource(String resourcePath) {

		byte[] fileContent = null;
		fileContent = loadFile(getResourceFile(resourcePath));
		return fileContent;
	}

	/**
	 * 读取 File 对象所代表的文件的内容
	 * 
	 * @param file
	 * @return
	 */
	public static byte[] loadFile(File file) {
		return loadFile(file, 0, -1);
	}

	/**
	 * 读取 File 对象所代表的文件的内容
	 * 
	 * @param file
	 *            文件对象
	 * @param beginPos
	 *            起始位置
	 * @param endPos
	 *            结束位置,如果值小于0则读取全部,如果大于文件的大小,则自动调整为文件的大小
	 * @return
	 */
	public static byte[] loadFile(File file, int beginPos, int endPos) {

		try {
			long fileSize = file.length();

			if (beginPos < 0) {
				return null;
			}

			if (endPos > fileSize) {
				endPos = (int) fileSize;
			}
			
			// 计算需要读取的差高难度
			int loadLength = 0;
			if (endPos < 0) {
				loadLength = (int) fileSize - beginPos + 1;
			} else {
				loadLength = endPos - beginPos + 1;
			}
			RandomAccessFile randomAccessFile = new RandomAccessFile(file, "r");
			byte[] fileBytes = new byte[(int) loadLength - 1];
			randomAccessFile.seek(beginPos);
			randomAccessFile.read(fileBytes);
			randomAccessFile.close();
			return fileBytes;
		} catch (IOException e) {
			//Logger.error(e);
		}
		return null;
	}
}
