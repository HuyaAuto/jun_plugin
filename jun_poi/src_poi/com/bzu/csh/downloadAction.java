package com.bzu.csh;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import jxl.Workbook;
import jxl.write.Label;
import jxl.write.WritableFont;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;

import org.apache.struts2.ServletActionContext;

import com.lowagie.text.Document;
import com.lowagie.text.Element;
import com.lowagie.text.Font;
import com.lowagie.text.PageSize;
import com.lowagie.text.Paragraph;
import com.lowagie.text.pdf.PdfPTable;
import com.lowagie.text.pdf.PdfWriter;
import com.opensymphony.xwork2.Action;

public class downloadAction implements Action {

	private String downType;

	public String getDownType() {
		return downType;
	}

	public void setDownType(String downType) {
		this.downType = downType;
	}

	public String execute() {
		// TODO Auto-generated method stub
		HttpServletRequest request = ServletActionContext.getRequest();
		//HttpServletResponse response = ServletActionContext.getResponse();
		//�˴�ģ�����ݿ���������ݡ�����������Ŀ�С����ǿ���ͨ����session�б����ǰ�����ݼ����滻����
		List<Person> list = new ArrayList<Person>();
		for (int i = 1; i < 6; i++) {
			Person person = new Person();
			person.setId(String.valueOf(i));
			person.setName(String.valueOf((char) (i + 64)));
			person.setAge(i + 20);
			person.setSex("man");
			list.add(person);
		}
		OutputStream os = null;
		String fname = "personlist";
		if ("PDF".equals(downType)) {
			try {
			//	response.reset();
			//	os = response.getOutputStream();
				FileOutputStream out = new FileOutputStream("d://a.pdf");
				Document document = new Document(PageSize.A4, 50, 50, 50, 50);
			//	response.setContentType("application/pdf");
			//	response.setHeader("Content-disposition",
			//			"attachment;filename=" + fname + ".pdf");
				ByteArrayOutputStream baos = new ByteArrayOutputStream();

				PdfWriter.getInstance(document, out);
				document.open();
				int cols = list.size();
				// ����PDF���
				PdfPTable table = new PdfPTable(4);
				// ����pdf���Ŀ��
				table.setTotalWidth(500);
				// �����Ƿ�Ҫ�̶�����
				table.setLockedWidth(true);
				// ��ͷ����
				Font thfont = new Font();
				// ���ñ�ͷ����Ĵ�С
				thfont.setSize(7);
				// ���ñ�ͷ�������ʽ
				thfont.setStyle(Font.BOLD);
				Font tdfont = new Font();
				tdfont.setSize(7);
				tdfont.setStyle(Font.NORMAL);
				// ����ˮƽ���뷽ʽ
				table.setHorizontalAlignment(Element.ALIGN_MIDDLE);
				// ����table��header
				table.addCell(new Paragraph("id", thfont));
				table.addCell(new Paragraph("name", thfont));
				table.addCell(new Paragraph("sex", thfont));
				table.addCell(new Paragraph("age", thfont));
				// ѭ������table��ÿһ��
				for (int i = 0; i < list.size(); i++) {
					Person p = (Person) list.get(i);
					table.addCell(new Paragraph(p.getId(), tdfont));
					table.addCell(new Paragraph(p.getName(), tdfont));
					table.addCell(new Paragraph(p.getSex(), tdfont));
					table.addCell(new Paragraph(String.valueOf(p.getAge()),
							tdfont));
				}
				document.add(table);
				document.close();
			//	baos.writeTo(response.getOutputStream());
				baos.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		} else if ("CSV".equals(downType)) {
		//	response.reset();
			// ����csv�ļ�
			//response.setHeader("Content-disposition", "attachment;filename="
			//		+ fname + ".csv");
			//response.setContentType("text/csv");
			//response.setCharacterEncoding("UTF-8");
			FileOutputStream out ;
			String sep = ",";
			try {
				out = new FileOutputStream(new File("d://a.csv"));
				//out = response.getOutputStream();
				out.write("id".getBytes());
				out.write(sep.getBytes());
				out.write("name".getBytes());
				out.write(sep.getBytes());
				out.write("sex".getBytes());
				out.write(sep.getBytes());
				out.write("age".getBytes());
				out.write(sep.getBytes());
				out.write(System.getProperty("line.separator").getBytes());
				for (int i = 0; i < list.size(); i++) {
					Person p = (Person) list.get(i);
					out.write(p.getId().getBytes());
					out.write((sep + "/t").getBytes());
					out.write(p.getName().getBytes());
					out.write((sep + "/t").getBytes());
					out.write(p.getSex().getBytes());
					out.write((sep + "/t").getBytes());
					out.write(String.valueOf(p.getAge()).getBytes());
					out.write((sep + "/t").getBytes());
					out.write(sep.getBytes());
					out.write(System.getProperty("line.separator").getBytes());
				}
				out.flush();
				//out.cloute();
			} catch (Exception e) {
				e.printStackTrace();
			}
		} else if (downType.equals("Excel")) {
			//response.reset();
			// ����xls�ļ�
			//response.setContentType("application/vnd.ms-excel");
			//response.setHeader("Content-disposition", "attachment;filename="
			//		+ fname + ".xls");
			try {
				//os = response.getOutputStream();
				Label l = null;
				WritableWorkbook wbook = Workbook.createWorkbook(new File(
						"d://a.xls"));
				// дsheet����
				WritableSheet sheet = wbook.createSheet("my excel file", 0);
				jxl.write.WritableFont wfc4 = new jxl.write.WritableFont(
						WritableFont.ARIAL, 9, WritableFont.NO_BOLD, false,
						jxl.format.UnderlineStyle.NO_UNDERLINE,
						jxl.format.Colour.BLACK);
				jxl.write.WritableCellFormat wcfFC4 = new jxl.write.WritableCellFormat(
						wfc4);
				wcfFC4.setBackground(jxl.format.Colour.LIGHT_GREEN);
				int col = 0;
				sheet.setColumnView(col, 12);
				l = new Label(col, 0, "id", wcfFC4);
				sheet.addCell(l);
				col++;
				sheet.setColumnView(col, 12);
				l = new Label(col, 0, "name", wcfFC4);
				sheet.addCell(l);
				col++;
				sheet.setColumnView(col, 12);
				l = new Label(col, 0, "sex", wcfFC4);
				sheet.addCell(l);
				col++;
				sheet.setColumnView(col, 12);
				l = new Label(col, 0, "age", wcfFC4);
				sheet.addCell(l);

				// ����������ʽ
				jxl.write.WritableFont wfc5 = new jxl.write.WritableFont(
						WritableFont.ARIAL, 9, WritableFont.NO_BOLD, false,
						jxl.format.UnderlineStyle.NO_UNDERLINE,
						jxl.format.Colour.BLACK);
				jxl.write.WritableCellFormat wcfFC5 = new jxl.write.WritableCellFormat(
						wfc5);
				for (int i = 0; i < list.size(); i++) {
					Person p = (Person) list.get(i);
					int j = 0;
					l = new Label(j, i + 1, p.getId(), wcfFC5);
					sheet.addCell(l);
					j++;
					l = new Label(j, i + 1, p.getName(), wcfFC5);
					sheet.addCell(l);
					j++;
					l = new Label(j, i + 1, p.getSex(), wcfFC5);
					sheet.addCell(l);
					j++;
					l = new Label(j, i + 1, String.valueOf(p.getAge()), wcfFC5);
					sheet.addCell(l);
					j++;
				}
				// д������
				wbook.write();
				wbook.close();

			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		return SUCCESS;
	}
}