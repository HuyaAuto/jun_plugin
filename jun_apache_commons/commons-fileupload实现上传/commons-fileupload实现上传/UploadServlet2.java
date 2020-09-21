package net.s2t181.userdemo.web.servlet;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.fileupload.DefaultFileItemFactory;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileItemFactory;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

public class FileServlet extends HttpServlet {
	PrintWriter out=null;
	/**
	 * �������� 
	 */
	public void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//�������� 
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=UTF-8");
		out= response.getWriter();
		
		
		//ȷ�����������Ƿ����ļ��ϴ�����
		boolean flag=ServletFileUpload.isMultipartContent(request);
		if(flag){
			//�����ļ��ϴ��Ĺ�������
			FileItemFactory factory=new DiskFileItemFactory();
			//����ServletFileUpload���󣬲�������������Ϊ��������
			ServletFileUpload upload=new ServletFileUpload(factory);
			//�����ϴ��ļ��Ĵ�С
			upload.setSizeMax(1024*1024*3); //3m
			//ʹ���ϴ��������������н������ύ�����б�Ԫ��
			try {
				List<FileItem> lstForms=upload.parseRequest(request);
				//�������б�Ԫ��
				for (FileItem fileItem : lstForms) {
					//�ж�ÿһ����Ԫ���Ƿ�����ͨ��
					if(fileItem.isFormField()){
						System.out.println(fileItem.getString("UTF-8"));
					}else{
						//�ϴ�ǰ׼������
						//a���ϴ����·��this.getServletContext().getRealPath("/")���ȥ��ǰ��Ŀ�� ����ķ������ϵľ���·��
					
						String path=this.getServletContext().getRealPath("/")+"files/";
						//b���ҳ�Ҫ�ϴ����ļ�������
						String fileName=fileItem.getName();
						fileName=fileName.substring(fileName.lastIndexOf("\\")+1);
						//c���ϴ�
						fileItem.write(new File(path+fileName));
						out.println("<h2>"+fileName+"�ϴ��ɹ���</h2>");
					}
				}
			} catch (Exception e) {
				System.out.println("����"+e.getMessage());
			}
		}else{
			System.out.println("û���ϴ�");
		}
		
		
		out.flush();
		out.close();
	}
	
}
