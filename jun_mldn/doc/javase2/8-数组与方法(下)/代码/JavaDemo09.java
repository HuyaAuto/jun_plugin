public class JavaDemo09
{
	public static void main(String args[])
	{
		int i[] = new int[10] ;
		// 调用init方法就可以为数组初始化
		init(i) ;
		// 打印数组
		print(i) ;
	}
	// 声明一个方法，要求此方法可以为数组中的内容初始化内容
	// 0--> 1、1--> 2
	// 把堆内存空间的内容取出，之后在方法中进行加工
	public static void init(int x[])
	{
		// 进行数组的初始化
		for (int y=0;y<x.length;y++)
		{
			x[y] = y + 1 ;
		}
	}
	// 定义第二个方法，此方法用于打印数组
	public static void print(int x[])
	{
		for (int y=0;y<x.length;y++)
		{
			System.out.println("数组["+y+"] = "+x[y]) ;
		}
	}
};