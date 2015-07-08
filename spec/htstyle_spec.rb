#!/usr/bin/env ruby

require 'htstyle'
require 'version'

describe HTStyle do
  it 'reads the example input' do
    $infile = File.read "spec/sockdem.c"
  end
  it 'reads the example output' do
    $outfile = File.read "spec/example_output.c"
  end
  it 'has a version number' do
    defined? HTStyle::VERSION
  end
  it 'gets the right output' do
    expect {HTStyle::indenter($infile)}.to output($outfile).to_stdout
  end
end

