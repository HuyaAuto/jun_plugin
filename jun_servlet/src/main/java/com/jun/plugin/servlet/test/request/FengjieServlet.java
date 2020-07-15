package com.itheima.request;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class FengjieServlet extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=utf-8");
		String ref = request.getHeader("Referer");
		if(ref==null || "".equals(ref) || !ref.startsWith("http://localhost")){
			response.sendRedirect(request.getContextPath()+"/index.html");
			return;
		}
		
		response.getWriter().write("�����һ���..���ں��������..�ջ��˺ܶ�ܶ�......");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
