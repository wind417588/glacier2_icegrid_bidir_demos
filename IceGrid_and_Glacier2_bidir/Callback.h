// **********************************************************************
//
// Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.7.1
//
// <auto-generated>
//
// Generated from file `Callback.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Callback_h__
#define __Callback_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/GCObject.h>
#include <Ice/Value.h>
#include <Ice/Incoming.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <Ice/Identity.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace Demo
{

class CallbackReceiver;
class CallbackReceiverPrx;
class CallbackSender;
class CallbackSenderPrx;

}

namespace Demo
{

class CallbackReceiver : public virtual ::Ice::Object
{
public:

    using ProxyType = CallbackReceiverPrx;

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(::std::string id, const ::Ice::Current& current) const override;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector<::std::string> ice_ids(const ::Ice::Current& current) const override;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual ::std::string ice_id(const ::Ice::Current& current) const override;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void callback(int num, const ::Ice::Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_callback(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&) override;
    /// \endcond
};

class CallbackSender : public virtual ::Ice::Object
{
public:

    using ProxyType = CallbackSenderPrx;

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(::std::string id, const ::Ice::Current& current) const override;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector<::std::string> ice_ids(const ::Ice::Current& current) const override;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual ::std::string ice_id(const ::Ice::Current& current) const override;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void addClient(::std::shared_ptr<CallbackReceiverPrx> receiver, const ::Ice::Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_addClient(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&) override;
    /// \endcond
};

}

namespace Demo
{

class CallbackReceiverPrx : public virtual ::Ice::Proxy<CallbackReceiverPrx, ::Ice::ObjectPrx>
{
public:

    void callback(int num, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &CallbackReceiverPrx::_iceI_callback, num, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto callbackAsync(int num, const ::Ice::Context& context = ::Ice::noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &CallbackReceiverPrx::_iceI_callback, num, context);
    }

    ::std::function<void()>
    callbackAsync(int num,
                  ::std::function<void()> response,
                  ::std::function<void(::std::exception_ptr)> ex = nullptr,
                  ::std::function<void(bool)> sent = nullptr,
                  const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(response, ex, sent, this, &CallbackReceiverPrx::_iceI_callback, num, context);
    }

    /// \cond INTERNAL
    void _iceI_callback(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, int, const ::Ice::Context&);
    /// \endcond

    /**
     * Obtains the Slice type ID of this interface.
     * @return The fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:

    /// \cond INTERNAL
    CallbackReceiverPrx() = default;
    friend ::std::shared_ptr<CallbackReceiverPrx> IceInternal::createProxy<CallbackReceiverPrx>();

    virtual ::std::shared_ptr<::Ice::ObjectPrx> _newInstance() const override;
    /// \endcond
};

class CallbackSenderPrx : public virtual ::Ice::Proxy<CallbackSenderPrx, ::Ice::ObjectPrx>
{
public:

    void addClient(const ::std::shared_ptr<CallbackReceiverPrx>& receiver, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &CallbackSenderPrx::_iceI_addClient, receiver, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto addClientAsync(const ::std::shared_ptr<CallbackReceiverPrx>& receiver, const ::Ice::Context& context = ::Ice::noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &CallbackSenderPrx::_iceI_addClient, receiver, context);
    }

    ::std::function<void()>
    addClientAsync(const ::std::shared_ptr<CallbackReceiverPrx>& receiver,
                   ::std::function<void()> response,
                   ::std::function<void(::std::exception_ptr)> ex = nullptr,
                   ::std::function<void(bool)> sent = nullptr,
                   const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(response, ex, sent, this, &CallbackSenderPrx::_iceI_addClient, receiver, context);
    }

    /// \cond INTERNAL
    void _iceI_addClient(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, const ::std::shared_ptr<CallbackReceiverPrx>&, const ::Ice::Context&);
    /// \endcond

    /**
     * Obtains the Slice type ID of this interface.
     * @return The fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:

    /// \cond INTERNAL
    CallbackSenderPrx() = default;
    friend ::std::shared_ptr<CallbackSenderPrx> IceInternal::createProxy<CallbackSenderPrx>();

    virtual ::std::shared_ptr<::Ice::ObjectPrx> _newInstance() const override;
    /// \endcond
};

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

/// \cond INTERNAL
namespace Demo
{

using CallbackReceiverPtr = ::std::shared_ptr<CallbackReceiver>;
using CallbackReceiverPrxPtr = ::std::shared_ptr<CallbackReceiverPrx>;

using CallbackSenderPtr = ::std::shared_ptr<CallbackSender>;
using CallbackSenderPrxPtr = ::std::shared_ptr<CallbackSenderPrx>;

}
/// \endcond

#else // C++98 mapping

namespace IceProxy
{

namespace Demo
{

class CallbackReceiver;
/// \cond INTERNAL
void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< ::IceProxy::Demo::CallbackReceiver>&);
::IceProxy::Ice::Object* upCast(::IceProxy::Demo::CallbackReceiver*);
/// \endcond

class CallbackSender;
/// \cond INTERNAL
void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< ::IceProxy::Demo::CallbackSender>&);
::IceProxy::Ice::Object* upCast(::IceProxy::Demo::CallbackSender*);
/// \endcond

}

}

namespace Demo
{

class CallbackReceiver;
/// \cond INTERNAL
::Ice::Object* upCast(CallbackReceiver*);
/// \endcond
typedef ::IceInternal::Handle< CallbackReceiver> CallbackReceiverPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Demo::CallbackReceiver> CallbackReceiverPrx;
typedef CallbackReceiverPrx CallbackReceiverPrxPtr;
/// \cond INTERNAL
void _icePatchObjectPtr(CallbackReceiverPtr&, const ::Ice::ObjectPtr&);
/// \endcond

class CallbackSender;
/// \cond INTERNAL
::Ice::Object* upCast(CallbackSender*);
/// \endcond
typedef ::IceInternal::Handle< CallbackSender> CallbackSenderPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Demo::CallbackSender> CallbackSenderPrx;
typedef CallbackSenderPrx CallbackSenderPrxPtr;
/// \cond INTERNAL
void _icePatchObjectPtr(CallbackSenderPtr&, const ::Ice::ObjectPtr&);
/// \endcond

}

namespace Demo
{

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::Demo::CallbackReceiver::begin_callback.
 * Create a wrapper instance by calling ::Demo::newCallback_CallbackReceiver_callback.
 */
class Callback_CallbackReceiver_callback_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_CallbackReceiver_callback_Base> Callback_CallbackReceiver_callbackPtr;

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::Demo::CallbackSender::begin_addClient.
 * Create a wrapper instance by calling ::Demo::newCallback_CallbackSender_addClient.
 */
class Callback_CallbackSender_addClient_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_CallbackSender_addClient_Base> Callback_CallbackSender_addClientPtr;

}

namespace IceProxy
{

namespace Demo
{

class CallbackReceiver : public virtual ::Ice::Proxy<CallbackReceiver, ::IceProxy::Ice::Object>
{
public:

    void callback(::Ice::Int num, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_callback(_iceI_begin_callback(num, context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_callback(::Ice::Int num, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_callback(num, context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_callback(::Ice::Int num, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_callback(num, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_callback(::Ice::Int num, const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_callback(num, context, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_callback(::Ice::Int num, const ::Demo::Callback_CallbackReceiver_callbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_callback(num, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_callback(::Ice::Int num, const ::Ice::Context& context, const ::Demo::Callback_CallbackReceiver_callbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_callback(num, context, cb, cookie);
    }

    void end_callback(const ::Ice::AsyncResultPtr& result);

private:

    ::Ice::AsyncResultPtr _iceI_begin_callback(::Ice::Int, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    /**
     * Obtains the Slice type ID corresponding to this interface.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:
    /// \cond INTERNAL

    virtual ::IceProxy::Ice::Object* _newInstance() const;
    /// \endcond
};

class CallbackSender : public virtual ::Ice::Proxy<CallbackSender, ::IceProxy::Ice::Object>
{
public:

    void addClient(const ::Demo::CallbackReceiverPrx& receiver, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_addClient(_iceI_begin_addClient(receiver, context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_addClient(const ::Demo::CallbackReceiverPrx& receiver, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_addClient(receiver, context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_addClient(const ::Demo::CallbackReceiverPrx& receiver, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_addClient(receiver, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_addClient(const ::Demo::CallbackReceiverPrx& receiver, const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_addClient(receiver, context, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_addClient(const ::Demo::CallbackReceiverPrx& receiver, const ::Demo::Callback_CallbackSender_addClientPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_addClient(receiver, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_addClient(const ::Demo::CallbackReceiverPrx& receiver, const ::Ice::Context& context, const ::Demo::Callback_CallbackSender_addClientPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_addClient(receiver, context, cb, cookie);
    }

    void end_addClient(const ::Ice::AsyncResultPtr& result);

private:

    ::Ice::AsyncResultPtr _iceI_begin_addClient(const ::Demo::CallbackReceiverPrx&, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    /**
     * Obtains the Slice type ID corresponding to this interface.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:
    /// \cond INTERNAL

    virtual ::IceProxy::Ice::Object* _newInstance() const;
    /// \endcond
};

}

}

namespace Demo
{

class CallbackReceiver : public virtual ::Ice::Object
{
public:

    typedef CallbackReceiverPrx ProxyType;
    typedef CallbackReceiverPtr PointerType;

    virtual ~CallbackReceiver();

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(const ::std::string& id, const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual const ::std::string& ice_id(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void callback(::Ice::Int num, const ::Ice::Current& current = ::Ice::emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_callback(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

protected:

    /// \cond STREAM
    virtual void _iceWriteImpl(::Ice::OutputStream*) const;
    virtual void _iceReadImpl(::Ice::InputStream*);
    /// \endcond
};

/// \cond INTERNAL
inline bool operator==(const CallbackReceiver& lhs, const CallbackReceiver& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) == static_cast<const ::Ice::Object&>(rhs);
}

inline bool operator<(const CallbackReceiver& lhs, const CallbackReceiver& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) < static_cast<const ::Ice::Object&>(rhs);
}
/// \endcond

class CallbackSender : public virtual ::Ice::Object
{
public:

    typedef CallbackSenderPrx ProxyType;
    typedef CallbackSenderPtr PointerType;

    virtual ~CallbackSender();

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(const ::std::string& id, const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual const ::std::string& ice_id(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual void addClient(const CallbackReceiverPrx& receiver, const ::Ice::Current& current = ::Ice::emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_addClient(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

protected:

    /// \cond STREAM
    virtual void _iceWriteImpl(::Ice::OutputStream*) const;
    virtual void _iceReadImpl(::Ice::InputStream*);
    /// \endcond
};

/// \cond INTERNAL
inline bool operator==(const CallbackSender& lhs, const CallbackSender& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) == static_cast<const ::Ice::Object&>(rhs);
}

inline bool operator<(const CallbackSender& lhs, const CallbackSender& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) < static_cast<const ::Ice::Object&>(rhs);
}
/// \endcond

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

namespace Demo
{

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::Demo::CallbackReceiver::begin_callback.
 * Create a wrapper instance by calling ::Demo::newCallback_CallbackReceiver_callback.
 */
template<class T>
class CallbackNC_CallbackReceiver_callback : public Callback_CallbackReceiver_callback_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_CallbackReceiver_callback(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackReceiver::begin_callback.
 */
template<class T> Callback_CallbackReceiver_callbackPtr
newCallback_CallbackReceiver_callback(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CallbackReceiver_callback<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackReceiver::begin_callback.
 */
template<class T> Callback_CallbackReceiver_callbackPtr
newCallback_CallbackReceiver_callback(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CallbackReceiver_callback<T>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackReceiver::begin_callback.
 */
template<class T> Callback_CallbackReceiver_callbackPtr
newCallback_CallbackReceiver_callback(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CallbackReceiver_callback<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackReceiver::begin_callback.
 */
template<class T> Callback_CallbackReceiver_callbackPtr
newCallback_CallbackReceiver_callback(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CallbackReceiver_callback<T>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::Demo::CallbackReceiver::begin_callback.
 * Create a wrapper instance by calling ::Demo::newCallback_CallbackReceiver_callback.
 */
template<class T, typename CT>
class Callback_CallbackReceiver_callback : public Callback_CallbackReceiver_callback_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_CallbackReceiver_callback(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackReceiver::begin_callback.
 */
template<class T, typename CT> Callback_CallbackReceiver_callbackPtr
newCallback_CallbackReceiver_callback(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CallbackReceiver_callback<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackReceiver::begin_callback.
 */
template<class T, typename CT> Callback_CallbackReceiver_callbackPtr
newCallback_CallbackReceiver_callback(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CallbackReceiver_callback<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackReceiver::begin_callback.
 */
template<class T, typename CT> Callback_CallbackReceiver_callbackPtr
newCallback_CallbackReceiver_callback(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CallbackReceiver_callback<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackReceiver::begin_callback.
 */
template<class T, typename CT> Callback_CallbackReceiver_callbackPtr
newCallback_CallbackReceiver_callback(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CallbackReceiver_callback<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::Demo::CallbackSender::begin_addClient.
 * Create a wrapper instance by calling ::Demo::newCallback_CallbackSender_addClient.
 */
template<class T>
class CallbackNC_CallbackSender_addClient : public Callback_CallbackSender_addClient_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_CallbackSender_addClient(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackSender::begin_addClient.
 */
template<class T> Callback_CallbackSender_addClientPtr
newCallback_CallbackSender_addClient(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CallbackSender_addClient<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackSender::begin_addClient.
 */
template<class T> Callback_CallbackSender_addClientPtr
newCallback_CallbackSender_addClient(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CallbackSender_addClient<T>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackSender::begin_addClient.
 */
template<class T> Callback_CallbackSender_addClientPtr
newCallback_CallbackSender_addClient(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CallbackSender_addClient<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackSender::begin_addClient.
 */
template<class T> Callback_CallbackSender_addClientPtr
newCallback_CallbackSender_addClient(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_CallbackSender_addClient<T>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::Demo::CallbackSender::begin_addClient.
 * Create a wrapper instance by calling ::Demo::newCallback_CallbackSender_addClient.
 */
template<class T, typename CT>
class Callback_CallbackSender_addClient : public Callback_CallbackSender_addClient_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_CallbackSender_addClient(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackSender::begin_addClient.
 */
template<class T, typename CT> Callback_CallbackSender_addClientPtr
newCallback_CallbackSender_addClient(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CallbackSender_addClient<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackSender::begin_addClient.
 */
template<class T, typename CT> Callback_CallbackSender_addClientPtr
newCallback_CallbackSender_addClient(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CallbackSender_addClient<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackSender::begin_addClient.
 */
template<class T, typename CT> Callback_CallbackSender_addClientPtr
newCallback_CallbackSender_addClient(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CallbackSender_addClient<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Demo::CallbackSender::begin_addClient.
 */
template<class T, typename CT> Callback_CallbackSender_addClientPtr
newCallback_CallbackSender_addClient(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_CallbackSender_addClient<T, CT>(instance, 0, excb, sentcb);
}

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
