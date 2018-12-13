/*
1. 数据类型：
	1） 数值
	2） 文本 + 二进制
	3） 日期时间
	
2. 字面量
	不加引号(' 或者 ")	数值
	加了引号 			文本/日期时间
*/
	
	
-- 创建今天的库，并使用
CREATE DATABASE 43ban_1213;
USE 43ban_1213;

-- 创建学生表
-- ***
CREATE TABLE student (
	id INT,
	name VARCHAR(20),
	gender VARCHAR(2)
);

-- 查看库里所有的表
-- ***
SHOW TABLES;

-- 查看创建表的结构
-- ***
-- 1.
SHOW CREATE TABLE student;

-- 2.
DESC student;

--
-- 创建一个 class 引擎 是 MyISAM
CREATE TABLE class (
	id int,
	name varchar(20)
)	ENGINE MyISAM;



-- 插入测试班级数据
INSERT INTO class (id, name) VALUES
	(1, '三国'),
	(2, '西游'),
	(3, '水浒'),
	(4, '红楼');
	
-- 插入测试同学数据
INSERT INTO student (id, name, gender) VALUES
	(1, '曹孟德', '男'),
	(2, '孙悟空', '不详'),
	(3, '宋公明', '男'),
	(4, '林黛玉', '女'),
	(5, '贾宝玉', '男');
	
-- 修改 student 表结构，增加班级 id 字段
-- **
ALTER TABLE student ADD class_id int;

-- 修改 student 表结构，删除 gender 字段
ALTER TABLE student DROP gender;


-- 修改 student 表结构，增加 gender 字段，跟在 name 后面
-- **
ALTER TABLE student ADD gender varchar(2) AFTER name;

-- 修改 student 表结构, 更改 name 类型 varchar(20) -> varchar(100)
-- **
ALTER TABLE student MODIFY name VARCHAR(100);



-- 一旦数据过长，不能再缩小了
INSERT INTO student (id, name, gender, class_id) VALUES (6, '帕布罗.迭戈.荷瑟.山迪亚哥. 弗朗西斯科.德.保拉.居安.尼波莫切诺.克瑞斯皮尼亚诺.德.罗斯.瑞米迪欧斯.西波瑞亚诺.德.拉.山迪西玛.特立尼达.玛利亚.帕里西奥.克里托.瑞兹.布拉斯科.毕加索', '男', 4);

-- 这里会报错
ALTER TABLE student MODIFY name VARCHAR(20);

-- gender --》 sex
ALTER TABLE student CHANGE gender sex varchar(2);


-- 表改名
RENAME TABLE student TO student_1;

-- 演示 SQL，不能执行，效果类似 C 语言里交换
-- **
RENAME TABLE student TO temp, 
	student_1 TO student, 
	temp TO student_1;

-- 删表
DROP TABLE student_1;


-- 查看表里的数据
SELECT * FROM class;

-- 修改表里的数据
-- 把 student 表里的 id 为 1 的同学的 class_id
-- 改为 3
UPDATE student SET class_id = 3 WHERE id = 1;




--- 第四章
create table tt1(num tinyint);


create table users ( id int, title varchar(20), content text, published_at datetime, created_at timestamp default current_timestamp );



int(数字)		只是显示长度，用处不大，和zerofill有关
float(m, d)		m整体长度，d小数点后
decimal(m, d)	m整体长度，d小数点后
char/varchar(l)	l 整体字符个数，整个字节数不超过 66535
bit(m)			位长度











































