package com.itheima.request;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class CustInfoServlet extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//1.��ȡ�ͻ������������URL
		String url = request.getRequestURL().toString();
		System.out.println(url);
		//2.��ȡ�ͻ����������Դ���ֵ�����
		String uri = request.getRequestURI();
		System.out.println(uri);
		//3.��ȡ�������в�������
		String qStr = request.getQueryString();
		System.out.println(qStr);
		//4.��ȡ����ͻ��˵�ip��ַ
		String ip = request.getRemoteAddr();
		System.out.println(ip);
		//5.��ȡ�ͻ���������ʽ
		String method = request.getMethod();
		System.out.println(method);
		//6.��ȡ��ǰwebӦ�õ�����
		String name = request.getContextPath();
		System.out.println(name);
		
		response.sendRedirect(request.getContextPath()+"/index.jsp");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
