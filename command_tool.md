我这个项目主要是记录算法的学习 现在想要实现一个脚手架 能够通过命令行实现

1. 一行命令实现 C++ 代码的编译和运行 Languague 使用 GUN G++17 7.3.0
2. 一行命令实现 Golang 代码的编译和运行 就使用当前环境的 Go Version 就行
3. 需要创建一个 package 用于存放 in 和 out 文件, 能够通过一行实现 指定文件运行自动读入 in 文件 然后比对 out 文件
   i. in文件的读取可以写到模版文件中,并且以注释的形式存在, 用户可以手动放开注释或者在运行check的时候放开注释
4. 一行命令创建 c++ / go 的模板文件
5. 任何编译产生的临时文件我都想要保存,如果不能够做到或者对性能有影响,那么只能够允许多次运行编译只会产生一个文件

如果可以的话 建议命令变成
gzm-call c++/go run file_name 
gzm-call c++/go check file_name
gzm-call c++/go new file_name


