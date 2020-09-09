# sea-rpc
## ģ��
- rpc-core:
  ��ģ����rpcĿǰ�����д���
- rpc-demo
  ��ģ����demo,����server��client�Ĵ���

## �������demo
�޸�rpc-demoλ��src/main/resources�µ������ļ�,�����ļ�˵�����£�
-     netty_server.properties ����������Netty Server�������˿ں�
-     zk_servers.properties ����������zookeeper�ķ������б�
-     log4j.properties

���븸����sea-rpc(����������ģ��rpc-core��rpc-demo)��  
    ��rpc-demo������tomcat�£���������log��˵��Netty Server����������Netty Server started at 192.168.1.104:9090 in 323 ms�� (����192.168.1.104�Ǳ���Netty server������ip,9090��Netty server�������˿�)  
���пͻ��˲��Գ���com.github.ghsea.rpc.demo.client.HelloTest  

## ����demo�����˵��
- �����

```
	<bean id="serverBootstrap" class="com.github.ghsea.rpc.server.RpcServerBootstrap"></bean>

<bean id="helloImpl" class="com.github.ghsea.rpc.demo.server.service.impl.HelloImpl" />

<sea-rpc:provider id="hello"
		interface="com.github.ghsea.rpc.server.test.Hello" ref="helloImpl"
		pool="groupon-data" version="1.0-ghsea" />
```
����serverBootstrap�Ǳ������õģ����൱��Netty server��������  
sea-rpc:provider id="hello"��helloImpl��¶Ϊһ��Զ�̷���

- �ͻ���

```
<sea-rpc:client id="helloClient" targetService="hello"
		targetInterface="com.github.ghsea.rpc.server.test.Hello" poolName="groupon-data"
		groupName="mobile" version="1.0-ghsea" timeoutMs="20000" retryTimes="5"
		callType="SYNC" />
```
targetService������Զ�̷��������������˵�provider id��һ�¡�  
targetInterface��Զ�̷���Ľӿ����͡�  
ʣ�µļ������ö����˿ͻ��˵�һЩ��Ϊ:
- poolName�����˵�pool���Ӧ
- version�����˵�version���Ӧ
- timeoutMs�����˵�������ĳ�ʱʱ��
- retryTimes�����˿ͻ��˵����Դ���(Ŀǰ��δʵ��)
- callType�����˿ͻ��˵ĵ������ͣ�ͬ��(SYNC),�첽(ASYNC)  
�������õ�xsd����rpc-coreģ��� com/github/ghsea/rpc/common/spring/sea-rpc.xsd