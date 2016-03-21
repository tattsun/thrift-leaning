#
# Autogenerated by Thrift Compiler (0.9.3)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#

require 'thrift'
require 'hello_types'

module Greeter
  class Client
    include ::Thrift::Client

    def greet(h)
      send_greet(h)
      return recv_greet()
    end

    def send_greet(h)
      send_message('greet', Greet_args, :h => h)
    end

    def recv_greet()
      result = receive_message(Greet_result)
      return result.success unless result.success.nil?
      raise ::Thrift::ApplicationException.new(::Thrift::ApplicationException::MISSING_RESULT, 'greet failed: unknown result')
    end

  end

  class Processor
    include ::Thrift::Processor

    def process_greet(seqid, iprot, oprot)
      args = read_args(iprot, Greet_args)
      result = Greet_result.new()
      result.success = @handler.greet(args.h)
      write_result(result, oprot, 'greet', seqid)
    end

  end

  # HELPER FUNCTIONS AND STRUCTURES

  class Greet_args
    include ::Thrift::Struct, ::Thrift::Struct_Union
    H = 1

    FIELDS = {
      H => {:type => ::Thrift::Types::STRUCT, :name => 'h', :class => ::Human}
    }

    def struct_fields; FIELDS; end

    def validate
    end

    ::Thrift::Struct.generate_accessors self
  end

  class Greet_result
    include ::Thrift::Struct, ::Thrift::Struct_Union
    SUCCESS = 0

    FIELDS = {
      SUCCESS => {:type => ::Thrift::Types::STRING, :name => 'success'}
    }

    def struct_fields; FIELDS; end

    def validate
    end

    ::Thrift::Struct.generate_accessors self
  end

end

