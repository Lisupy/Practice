
#coding=utf-8
#Todo:
# * ListPrint还不会
# * Class Tree太复杂了


puts "==== Day 1 ===="

# 打印字符串"Hello World"
print "Hello World\r\n"
puts "Hello World"
# 在打印字符串"Hello, Ruby."中，找出"Ruby."的下标
puts "Hello, Ruby.".index("Ruby.")

# 打印你的名字10遍
 i = 0
 until i == 10
 	puts i,"darrenhp" 
 	i = i + 1
 end 

# 打印字符串"This is sentence number 1.", 其中的数字会一直变化到10
i = 1
until i > 10
	puts "This is sentence number #{i}."
	i = i + 1
end

# 从文件运行Ruby程序
# 在命令行下运行ruby do.rb

# 加分题： 随机数，并设计猜数程序
def guess_random
	rand =  Random.new
	fixed_number = rand.rand 1..10**5 
	puts "fixed_num:",fixed_number
	
	while  (guess_number = gets.to_i) != fixed_number
		if guess_number < fixed_number
			puts "Bigger"
		else 
			puts "Smaller"
		end
	end
end

#guess_random

puts "==== Day 2 ===="
# do_test_1
File.open("search.md", File::RDWR|File::CREAT, 0644) {|f| puts f.read.length}
			
f = File.open("search.md", File::RDWR|File::CREAT, 0644)
puts f.read.length

# =====List Print ====
puts "== List Print =="#！！每打4个换行一次， 还不知道怎么插入换行语句"
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16].each{|var| print var}
puts
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16].each_slice(4){|var| var.each{|v| print v}}
puts

# ==== New Tree ====
puts "== Tree =="
class Tree 
	attr_accessor :children, :node_name

	def initialize(children={})
		children.each_key{|t| @node_name = t}
		children.each_value{|childs| @children = childs.inject([]){|s, val| s.push(Tree.new(Hash[[val]])) } }		
	end

	def visit_all(&block)
		visit &block
		children.each{|c| c.visit_all &block}
	end

	def visit(&block)
		block.call self
	end
end

ruby_tree = Tree.new({'grandpa' => {'dad' => {'child 1' => {}, 'child 2' => {} }, 'uncle' => {'child 3' => {}, 'child 4' => {}} }})
ruby_tree.visit_all{|t| puts t.node_name}

# grep 
def ruby_grep(file, pattern)
	File.open(file).each{|t| print t if t.include?(pattern)}
end
ruby_grep("search.md", "#")


puts "==== Day 3 ===="

class ActsAsCsv
	def read
		file = File.new(self.class.to_s.downcase + '.txt')
		@headers = file.gets.chomp.split(', ')

		file.each do |row|
			@result << row.chomp.split(', ')
		end
	end

	def headers
		@headers
	end

	def csv_contents
		@result
	end

	def each(&block)
		#puts @result
		@result.each{|t| block.call(t)}
	end


	def initialize
		@result = []
		read
	end
end

class RubyCsv < ActsAsCsv
end

m = RubyCsv.new
puts m.headers.inspect
puts m.csv_contents.inspect
m.each{|row| puts row}