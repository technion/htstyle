lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'version'

Gem::Specification.new do |spec|
  spec.name          = "HTStyle"
  spec.version       = HTStyle::VERSION
  spec.authors       = ["Technion"]
  spec.email         = ["technion@lolware.net"]
  spec.summary       = %q{Implements Hacking Team code style}
  spec.description   = %q{Implements Hack Team code style}
  spec.homepage      = "https://github.com/technion/htstyle"
  spec.license       = "BSD"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.6"
  spec.add_development_dependency "rake"
end

