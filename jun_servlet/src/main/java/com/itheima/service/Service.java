package com.itheima.service;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

public class Service {
	public void methdo1() throws FileNotFoundException, IOException{
		//--��û��ServletContext�Ļ�����,�����Ҫ��ȡ��Դ,����ʹ����������Լ�����ķ�ʽ������Դ,
		//		����Ҫע��,����������ĸ�Ŀ¼������,�ʹ��ĸ�Ŀ¼������Դ,
		//		���Դ˴���·��һ��Ҫ��һ������������Ŀ¼��·��
		Properties prop = new Properties();
		prop.load(new FileReader(Service.class.getClassLoader().getResource("../../../config.properties").getPath()));
		System.out.println(prop.getProperty("username"));
		System.out.println(prop.getProperty("password"));
	}
}
