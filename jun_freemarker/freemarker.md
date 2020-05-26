�﷨���
��������
��java��ͬ��FreeMarker����Ҫ������������ͣ�ֱ�Ӹ�ֵ���ɡ�

�ַ����� value = "xxxx" ������������ַ� string = r"xxxx" �������ź�˫������һ���ġ�

��ֵ��value = 1.2����ֵ����ֱ�ӵ��ڣ����ǲ����ÿ�ѧ��������

����ֵ��true or  false��

List���ϣ�list = [1,2,3] ; list=[1..100] ��ʾ 1 �� 100 �ļ��ϣ���֮��Ȼ��

Map���ϣ�map = {"key" : "value" , "key2" : "value2"}��key �������ַ���Ŷ��

ʵ���ࣺ��EL���ʽ��ֱ࣬�ӵ������

�ַ�������
�ַ������ӣ�����ֱ��Ƕ��${"hello , ${name}"} �� Ҳ�����üӺ�${"hello , " + name}

�ַ�����ȡ��string[index]��index ������һ��ֵ��Ҳ���������� 0..2 ��ʾ�±��0��ʼ�����±�Ϊ2������һ������������

�Ƚ������
== �����ڣ���!= �������ڣ���gt�����ڣ���gte�����ڻ��ߵ��ڣ���lt��С�ڣ���lte��С�ڻ��ߵ��ڣ����������� >��<  ���ܻᱨ��

һ��� if ���ʹ��

�ڽ�����
FreeMarker �ṩ��һЩ�ڽ�������ת���������ṹ������?�ڽ������������Ϳ���ͨ���ڽ�������ת�����������

1. html�� ���ַ�������HTML���룻
2. cap_first�� ʹ�ַ�����һ����ĸ��д��
3. lower_case�� ���ַ���ת��Сд��
4. upper_case�� ���ַ���ת�ɴ�д��
5. size�� ��ü�����Ԫ�صĸ�����
6. int�� ȡ�����ֵ��������֡�

�������ж�
 !  ����ָ��ȱʧ������Ĭ��ֵ��һ�����ñ������ʹ��
??   ���жϱ����Ƿ���ڡ�һ�����ifʹ�� <#if value??></#if>

��ָ��
�������Ϊjava�ķ�װ�������������ط�ʹ�á���ָ��Ҳ��Ϊ�Զ���ָ�macroָ��

�﷨�ܼ򵥣�<#macro val > ����macro </#macro>; ʹ��macro <@val />  

�����ռ�

�������Ϊjava��import��䣬Ϊ��������ظ���һ����Ҫ�Ĺ������:·����Ӧ�ð�����д��ĸ��ʹ���»���_�ָ����myName --> my_name

�﷨�ܼ򵥣�<#import "xxx.ftl" as val> 

 

����û��˵�����﷨����Ϊ��javaһ����ûʲô�ر�֮��




FreeMarker Web
�����Ǻ�SpringMVC���ϵģ�SpringMVC�����þͲ���˵�ˣ�����Ҳд����ص����£�ͬʱҲ���ṩԴ��

������ص�jar pom.xml
 
<!-- freeMarker start -->
    <dependency>
         <groupId>org.freemarker</groupId>
         <artifactId>freemarker</artifactId>
         <version>2.3.20</version>
     </dependency>
     <dependency>
          <groupId>org.springframework</groupId>
          <artifactId>spring-context-support</artifactId>
          <version>4.1.4.RELEASE</version>
      </dependency>
  </dependencies> 
  <!-- freeMarker end --> 
  
springmvc�������ļ���
 
<!-- ����Freemarker -->
    <!-- ����InternalResourceViewResolver��ǰ�棬������freemarker -->  
    <bean id="freemarkerConfig" class="org.springframework.web.servlet.view.freemarker.FreeMarkerConfigurer">  
        <property name="templateLoaderPath" value="/WEB-INF/views/templates"/>  
    </bean>  
    <bean id="viewResolver" class="org.springframework.web.servlet.view.freemarker.FreeMarkerViewResolver">  
        <property name="prefix" value=""/>  
        <property name="suffix" value=".ftl"/>  
        <property name="contentType" value="text/html; charset=UTF-8"/>
    </bean> 
Controller ��
 
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class HelloFreeMarkerController {
    
    @RequestMapping("/helloFreeMarker")
    public String helloFreeMarker(Model model) {
        model.addAttribute("name","ITDragon����");  
        return "helloFreeMarker";
    }

} 
�����Freemarker�ļ�

���ƴ���
���ƴ���
<html>  
<head>  
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">  
<title>FreeMarker Web</title>  
</head>  
<body>  
    <h1>Hello ${name} !</h1>  
</body>  
</html> 