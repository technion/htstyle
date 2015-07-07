#!/usr/bin/env ruby

accum = 0
while (line = gets)
  line.lstrip!
  accum += 4 if line.chomp[-1] == '{'
  accum -= 4 if line.chomp[-1] == '}'
  white = 80 - line.length - accum
  accum = 0 if accum < 0
  puts " " * white + line
end
