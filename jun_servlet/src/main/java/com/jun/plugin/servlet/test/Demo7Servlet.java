package com.itheima;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
/**
 * ServletContext��ȡ��Դ�ļ�
 */
public class Demo7Servlet extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
//		File file = new File("config.properties");
//		System.out.println(file.getAbsolutePath());
		//--���д���·��,��ᵽ��������Ŀ¼ ��tomcat/binĿ¼��ȥ����Դ,�Ҳ���
		//--���д����·��,��ᵽ��������Ŀ¼�ĸ�Ŀ¼ ��tomcat/bin Ŀ¼�Ĵ���Ŀ¼,�ҵĻ���tomcat��e:/workspace/tomcatt6 �����ҵ���e:/��ȥ����Դ,�Ҳ���
		//--�����Ӳ��·��,�����ҵ���Դ,����һ����һ�����л���,�ܿ���Ӳ��·�����ǲ���ȷ����,Ҳ����
		//----����,��web������������ȡ��Դ�ļ�,����ʹ��ServletContext�ṩ�ķ������ж�ȡ,
		//		ԭ�����ڴ����·��ǰƴ�ӵ�ǰwebӦ�õ�Ӳ��·���Ӷ��õ���ǰ��Դ��Ӳ��·��,
		//		����webӦ�õ�Ӳ��·���Ƕ�̬��ȡ��,��ʹ���˷�������Ҳ����ȷ��,����·���ͱ�֤����Զ����ȷ��
		Properties prop = new Properties();
		prop.load(new FileReader(this.getServletContext().getRealPath("config.properties")));
		
		System.out.println(prop.getProperty("username"));
		System.out.println(prop.getProperty("password"));
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
