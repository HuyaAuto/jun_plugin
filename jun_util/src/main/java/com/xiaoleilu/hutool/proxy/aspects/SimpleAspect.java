package com.xiaoleilu.hutool.proxy.aspects;

import java.lang.reflect.Method;

import com.xiaoleilu.hutool.proxy.Aspect;

/**
 * 简单切面类，不做任何操作<br>
 * 可以继承此类实现自己需要的方法即可
 * 
 * @author Wujun
 *
 */
public class SimpleAspect extends Aspect{
	
	public SimpleAspect(Object target) {
		super(target);
	}

	@Override
	public boolean before(Object target, Method method, Object[] args) {
		//继承此类后实现此方法
		return true;
	}

	@Override
	public boolean after(Object target, Method method, Object[] args) {
		//继承此类后实现此方法
		return true;
	}

	@Override
	public boolean afterException(Object target, Method method, Object[] args, Throwable e) {
		//继承此类后实现此方法
		return true;
	}

}
