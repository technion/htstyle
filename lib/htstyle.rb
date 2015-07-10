# Main re-indent module for HTStyle. See https://github.com/technion/htstyle
module HTStyle
  module_function

  def indenter(handle = STDIN)
    accum = 0
    handle.each_line do |line|
      line.lstrip!
      line.chomp!
      accum += 4 if line[-1] == '{'
      accum -= 4 if line[-1] == '}'
      white = 80 - line.length - accum
      white = 0 if white < 0
      puts " " * white + line
    end
  end
end
