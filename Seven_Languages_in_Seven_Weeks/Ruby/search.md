# Day 1 #
* Ruby API文档

		http://ruby-doc.org/ 
		http://www.ruby-lang.org/zh_cn/documentation/ 
		http://www.ruby-lang.org/en/documentation/
	
* Programming Ruby：The PragmaticProgrammer's Guide [TFH08]的免费版本 
	* http://www.ruby-doc.org/docs/ProgrammingRuby/
	*
* 替换字符串某一部分的方法
	* http://www.ruby-doc.org/core-1.9.3/String.html，然后搜索replace
	* str[fixnum] = new_str click to toggle source
	* str[fixnum, fixnum] = new_str
	* str[range] = aString
	* str[regexp] = new_str
	* str[regexp, fixnum] = new_str
	* str[regexp, name] = new_str
	* str[other_str] = new_str

* 有关Ruby正则表达式的资料

	* http://www.ruby-doc.org/core-1.9.3/Regexp.html
	* 基本形式是 /.../ 和 %r{...}

* 有关Ruby区间（range）的资料

	* http://www.ruby-doc.org/core-1.9.3/Range.html
	* 基本形式是(s..e) 和 (s...e)


# Day 2 #
* 分别找到用代码块和不用代码块读取文件的方法，用代码块有什么好处？
	*	使用代码块的方法：

		``File.open("search.md", File::RDWR|File::CREAT, 0644) {|f| puts f.read.length}``
			

	*	不使用代码块的方法：

		``f = File.open("search.md", File::RDWR|File::CREAT, 0644)``

		``puts f.read.length``
				

	*	使用代码块让对文件的使用的代码“聚合”到一起，降低了阅读难度

* 如何把散列表转换成数组？数组能转换成散列表吗？

    `` ["a", "b", "c", "d"].inject({}) { |mem, var| mem[var]  }	``
    
	`` 数组应该是可以转换成散列表的，就是麻烦了点``
	``  

* 你能循环遍历散列表吗？
	
		`` {"a"=>1, "b"=>2}.cycle{|var| print var} ``

* Ruby的数组能当作栈来用，它还能用作哪些常用的数据结构？
	* 栈	  push，pop， [-1]
	* 队列  first, delete_at, [0], push
	* 关联数组 assoc，rassoc
	
  