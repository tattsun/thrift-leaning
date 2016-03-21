#!/usr/bin/env ruby

require 'rubygems'
require 'bundler/setup'

require 'thrift'

$:.push('gen-rb')
require 'greeter'

transport = Thrift::BufferedTransport.new(Thrift::Socket.new('localhost', 9090))
protocol = Thrift::BinaryProtocol.new(transport)
client = Greeter::Client.new(protocol)

transport.open

h = Human.new
h.name = 'ossan'
h.age = 40

puts client.greet(h)
