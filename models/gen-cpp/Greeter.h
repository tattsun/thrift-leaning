/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Greeter_H
#define Greeter_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "hello_types.h"

namespace hello {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class GreeterIf {
 public:
  virtual ~GreeterIf() {}
  virtual void greet(std::string& _return, const Human& h) = 0;
};

class GreeterIfFactory {
 public:
  typedef GreeterIf Handler;

  virtual ~GreeterIfFactory() {}

  virtual GreeterIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(GreeterIf* /* handler */) = 0;
};

class GreeterIfSingletonFactory : virtual public GreeterIfFactory {
 public:
  GreeterIfSingletonFactory(const boost::shared_ptr<GreeterIf>& iface) : iface_(iface) {}
  virtual ~GreeterIfSingletonFactory() {}

  virtual GreeterIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(GreeterIf* /* handler */) {}

 protected:
  boost::shared_ptr<GreeterIf> iface_;
};

class GreeterNull : virtual public GreeterIf {
 public:
  virtual ~GreeterNull() {}
  void greet(std::string& /* _return */, const Human& /* h */) {
    return;
  }
};

typedef struct _Greeter_greet_args__isset {
  _Greeter_greet_args__isset() : h(false) {}
  bool h :1;
} _Greeter_greet_args__isset;

class Greeter_greet_args {
 public:

  Greeter_greet_args(const Greeter_greet_args&);
  Greeter_greet_args& operator=(const Greeter_greet_args&);
  Greeter_greet_args() {
  }

  virtual ~Greeter_greet_args() throw();
  Human h;

  _Greeter_greet_args__isset __isset;

  void __set_h(const Human& val);

  bool operator == (const Greeter_greet_args & rhs) const
  {
    if (!(h == rhs.h))
      return false;
    return true;
  }
  bool operator != (const Greeter_greet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Greeter_greet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Greeter_greet_pargs {
 public:


  virtual ~Greeter_greet_pargs() throw();
  const Human* h;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Greeter_greet_result__isset {
  _Greeter_greet_result__isset() : success(false) {}
  bool success :1;
} _Greeter_greet_result__isset;

class Greeter_greet_result {
 public:

  Greeter_greet_result(const Greeter_greet_result&);
  Greeter_greet_result& operator=(const Greeter_greet_result&);
  Greeter_greet_result() : success() {
  }

  virtual ~Greeter_greet_result() throw();
  std::string success;

  _Greeter_greet_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Greeter_greet_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Greeter_greet_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Greeter_greet_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Greeter_greet_presult__isset {
  _Greeter_greet_presult__isset() : success(false) {}
  bool success :1;
} _Greeter_greet_presult__isset;

class Greeter_greet_presult {
 public:


  virtual ~Greeter_greet_presult() throw();
  std::string* success;

  _Greeter_greet_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class GreeterClient : virtual public GreeterIf {
 public:
  GreeterClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  GreeterClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void greet(std::string& _return, const Human& h);
  void send_greet(const Human& h);
  void recv_greet(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class GreeterProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<GreeterIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (GreeterProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_greet(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  GreeterProcessor(boost::shared_ptr<GreeterIf> iface) :
    iface_(iface) {
    processMap_["greet"] = &GreeterProcessor::process_greet;
  }

  virtual ~GreeterProcessor() {}
};

class GreeterProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  GreeterProcessorFactory(const ::boost::shared_ptr< GreeterIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< GreeterIfFactory > handlerFactory_;
};

class GreeterMultiface : virtual public GreeterIf {
 public:
  GreeterMultiface(std::vector<boost::shared_ptr<GreeterIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~GreeterMultiface() {}
 protected:
  std::vector<boost::shared_ptr<GreeterIf> > ifaces_;
  GreeterMultiface() {}
  void add(boost::shared_ptr<GreeterIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void greet(std::string& _return, const Human& h) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->greet(_return, h);
    }
    ifaces_[i]->greet(_return, h);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class GreeterConcurrentClient : virtual public GreeterIf {
 public:
  GreeterConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  GreeterConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void greet(std::string& _return, const Human& h);
  int32_t send_greet(const Human& h);
  void recv_greet(std::string& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
