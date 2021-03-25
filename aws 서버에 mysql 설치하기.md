# aws 서버에 mysql 설치하기(with mobaXterm)

**버전**

mysql 8.0.23

[참고: https://abc1211.tistory.com/287]


sudo apt-get install mysql-server

mysql -u root -p

> 여기서 1045 (28000): access denied for user 'root'@'localhost' 에러 발생
>
> [참고: https://velog.io/@yhe228/ERRORmysql-ERROR-1698-28000-Access-denied-for-user-rootlocalhost]
>
> 다시 mysql -u root -p 입력 후 password 에 enter 값 입력



**외부접속 허용**

sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf

> bind-address  = 0.0.0.0 #이렇게 바꾸고
>
> mysqlx-bind-address    = 127.0.0.1 #주석처리 해야함

sudo service mysql restart



**mysql 비밀번호 바꾸기**

1. select host, user, plugin, authentication_string, password_last_changed from user;

2. alter user 'root'@'%' identified with mysql_native_password by 'pw123';

3. flush privileges;

   [참고: https://to-dy.tistory.com/58 ]



grant all privileges on ~~~ 입력 시 

ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'identified by ~ 에러 발생

참고 : https://stackoverflow.com/questions/50177216/how-to-grant-all-privileges-to-root-user-in-mysql-8-0

https://sikaleo.tistory.com/21

create user 'ssafy'@'%' identified by 'ssafy';

grant all privileges on *.* to ssafy@'%';



