// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Basic.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Basic.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* HeartBeat_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HeartBeat_reflection_ = NULL;
const ::google::protobuf::Descriptor* CommonRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CommonRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ResponseHeader_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ResponseHeader_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* UserSex_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_Basic_2eproto() {
  protobuf_AddDesc_Basic_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Basic.proto");
  GOOGLE_CHECK(file != NULL);
  HeartBeat_descriptor_ = file->message_type(0);
  static const int HeartBeat_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartBeat, tag_),
  };
  HeartBeat_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      HeartBeat_descriptor_,
      HeartBeat::default_instance_,
      HeartBeat_offsets_,
      -1,
      -1,
      -1,
      sizeof(HeartBeat),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartBeat, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeartBeat, _is_default_instance_));
  CommonRequest_descriptor_ = file->message_type(1);
  static const int CommonRequest_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CommonRequest, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CommonRequest, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CommonRequest, uid_),
  };
  CommonRequest_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      CommonRequest_descriptor_,
      CommonRequest::default_instance_,
      CommonRequest_offsets_,
      -1,
      -1,
      -1,
      sizeof(CommonRequest),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CommonRequest, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CommonRequest, _is_default_instance_));
  ResponseHeader_descriptor_ = file->message_type(2);
  static const int ResponseHeader_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, from_),
  };
  ResponseHeader_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ResponseHeader_descriptor_,
      ResponseHeader::default_instance_,
      ResponseHeader_offsets_,
      -1,
      -1,
      -1,
      sizeof(ResponseHeader),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, _is_default_instance_));
  UserSex_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Basic_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      HeartBeat_descriptor_, &HeartBeat::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      CommonRequest_descriptor_, &CommonRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ResponseHeader_descriptor_, &ResponseHeader::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Basic_2eproto() {
  delete HeartBeat::default_instance_;
  delete HeartBeat_reflection_;
  delete CommonRequest::default_instance_;
  delete CommonRequest_reflection_;
  delete ResponseHeader::default_instance_;
  delete ResponseHeader_reflection_;
}

void protobuf_AddDesc_Basic_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013Basic.proto\"\030\n\tHeartBeat\022\013\n\003tag\030\001 \001(\r\""
    "6\n\rCommonRequest\022\n\n\002id\030\001 \001(\005\022\014\n\004type\030\002 \001"
    "(\005\022\013\n\003uid\030\003 \001(\005\"8\n\016ResponseHeader\022\n\n\002id\030"
    "\001 \001(\005\022\014\n\004type\030\002 \001(\005\022\014\n\004from\030\003 \001(\014*,\n\007Use"
    "rSex\022\n\n\006female\020\000\022\010\n\004male\020\001\022\013\n\007unknown\020\002b"
    "\006proto3", 207);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Basic.proto", &protobuf_RegisterTypes);
  HeartBeat::default_instance_ = new HeartBeat();
  CommonRequest::default_instance_ = new CommonRequest();
  ResponseHeader::default_instance_ = new ResponseHeader();
  HeartBeat::default_instance_->InitAsDefaultInstance();
  CommonRequest::default_instance_->InitAsDefaultInstance();
  ResponseHeader::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Basic_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Basic_2eproto {
  StaticDescriptorInitializer_Basic_2eproto() {
    protobuf_AddDesc_Basic_2eproto();
  }
} static_descriptor_initializer_Basic_2eproto_;
const ::google::protobuf::EnumDescriptor* UserSex_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UserSex_descriptor_;
}
bool UserSex_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int HeartBeat::kTagFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

HeartBeat::HeartBeat()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:HeartBeat)
}

void HeartBeat::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

HeartBeat::HeartBeat(const HeartBeat& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:HeartBeat)
}

void HeartBeat::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  tag_ = 0u;
}

HeartBeat::~HeartBeat() {
  // @@protoc_insertion_point(destructor:HeartBeat)
  SharedDtor();
}

void HeartBeat::SharedDtor() {
  if (this != default_instance_) {
  }
}

void HeartBeat::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HeartBeat::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HeartBeat_descriptor_;
}

const HeartBeat& HeartBeat::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Basic_2eproto();
  return *default_instance_;
}

HeartBeat* HeartBeat::default_instance_ = NULL;

HeartBeat* HeartBeat::New(::google::protobuf::Arena* arena) const {
  HeartBeat* n = new HeartBeat;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void HeartBeat::Clear() {
// @@protoc_insertion_point(message_clear_start:HeartBeat)
  tag_ = 0u;
}

bool HeartBeat::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:HeartBeat)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 tag = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &tag_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:HeartBeat)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:HeartBeat)
  return false;
#undef DO_
}

void HeartBeat::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:HeartBeat)
  // optional uint32 tag = 1;
  if (this->tag() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->tag(), output);
  }

  // @@protoc_insertion_point(serialize_end:HeartBeat)
}

::google::protobuf::uint8* HeartBeat::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:HeartBeat)
  // optional uint32 tag = 1;
  if (this->tag() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->tag(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:HeartBeat)
  return target;
}

int HeartBeat::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:HeartBeat)
  int total_size = 0;

  // optional uint32 tag = 1;
  if (this->tag() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->tag());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HeartBeat::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:HeartBeat)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const HeartBeat* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const HeartBeat>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:HeartBeat)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:HeartBeat)
    MergeFrom(*source);
  }
}

void HeartBeat::MergeFrom(const HeartBeat& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:HeartBeat)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.tag() != 0) {
    set_tag(from.tag());
  }
}

void HeartBeat::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:HeartBeat)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeartBeat::CopyFrom(const HeartBeat& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:HeartBeat)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeartBeat::IsInitialized() const {

  return true;
}

void HeartBeat::Swap(HeartBeat* other) {
  if (other == this) return;
  InternalSwap(other);
}
void HeartBeat::InternalSwap(HeartBeat* other) {
  std::swap(tag_, other->tag_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata HeartBeat::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HeartBeat_descriptor_;
  metadata.reflection = HeartBeat_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// HeartBeat

// optional uint32 tag = 1;
void HeartBeat::clear_tag() {
  tag_ = 0u;
}
 ::google::protobuf::uint32 HeartBeat::tag() const {
  // @@protoc_insertion_point(field_get:HeartBeat.tag)
  return tag_;
}
 void HeartBeat::set_tag(::google::protobuf::uint32 value) {
  
  tag_ = value;
  // @@protoc_insertion_point(field_set:HeartBeat.tag)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CommonRequest::kIdFieldNumber;
const int CommonRequest::kTypeFieldNumber;
const int CommonRequest::kUidFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CommonRequest::CommonRequest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:CommonRequest)
}

void CommonRequest::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

CommonRequest::CommonRequest(const CommonRequest& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:CommonRequest)
}

void CommonRequest::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  id_ = 0;
  type_ = 0;
  uid_ = 0;
}

CommonRequest::~CommonRequest() {
  // @@protoc_insertion_point(destructor:CommonRequest)
  SharedDtor();
}

void CommonRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CommonRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CommonRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CommonRequest_descriptor_;
}

const CommonRequest& CommonRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Basic_2eproto();
  return *default_instance_;
}

CommonRequest* CommonRequest::default_instance_ = NULL;

CommonRequest* CommonRequest::New(::google::protobuf::Arena* arena) const {
  CommonRequest* n = new CommonRequest;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void CommonRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:CommonRequest)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(CommonRequest, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<CommonRequest*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(id_, uid_);

#undef ZR_HELPER_
#undef ZR_

}

bool CommonRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CommonRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_type;
        break;
      }

      // optional int32 type = 2;
      case 2: {
        if (tag == 16) {
         parse_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &type_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_uid;
        break;
      }

      // optional int32 uid = 3;
      case 3: {
        if (tag == 24) {
         parse_uid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &uid_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:CommonRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CommonRequest)
  return false;
#undef DO_
}

void CommonRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CommonRequest)
  // optional int32 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional int32 type = 2;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->type(), output);
  }

  // optional int32 uid = 3;
  if (this->uid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->uid(), output);
  }

  // @@protoc_insertion_point(serialize_end:CommonRequest)
}

::google::protobuf::uint8* CommonRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:CommonRequest)
  // optional int32 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional int32 type = 2;
  if (this->type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->type(), target);
  }

  // optional int32 uid = 3;
  if (this->uid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->uid(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:CommonRequest)
  return target;
}

int CommonRequest::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:CommonRequest)
  int total_size = 0;

  // optional int32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  // optional int32 type = 2;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->type());
  }

  // optional int32 uid = 3;
  if (this->uid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->uid());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CommonRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:CommonRequest)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const CommonRequest* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const CommonRequest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:CommonRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:CommonRequest)
    MergeFrom(*source);
  }
}

void CommonRequest::MergeFrom(const CommonRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CommonRequest)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.type() != 0) {
    set_type(from.type());
  }
  if (from.uid() != 0) {
    set_uid(from.uid());
  }
}

void CommonRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:CommonRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CommonRequest::CopyFrom(const CommonRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CommonRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CommonRequest::IsInitialized() const {

  return true;
}

void CommonRequest::Swap(CommonRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CommonRequest::InternalSwap(CommonRequest* other) {
  std::swap(id_, other->id_);
  std::swap(type_, other->type_);
  std::swap(uid_, other->uid_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata CommonRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CommonRequest_descriptor_;
  metadata.reflection = CommonRequest_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// CommonRequest

// optional int32 id = 1;
void CommonRequest::clear_id() {
  id_ = 0;
}
 ::google::protobuf::int32 CommonRequest::id() const {
  // @@protoc_insertion_point(field_get:CommonRequest.id)
  return id_;
}
 void CommonRequest::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:CommonRequest.id)
}

// optional int32 type = 2;
void CommonRequest::clear_type() {
  type_ = 0;
}
 ::google::protobuf::int32 CommonRequest::type() const {
  // @@protoc_insertion_point(field_get:CommonRequest.type)
  return type_;
}
 void CommonRequest::set_type(::google::protobuf::int32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:CommonRequest.type)
}

// optional int32 uid = 3;
void CommonRequest::clear_uid() {
  uid_ = 0;
}
 ::google::protobuf::int32 CommonRequest::uid() const {
  // @@protoc_insertion_point(field_get:CommonRequest.uid)
  return uid_;
}
 void CommonRequest::set_uid(::google::protobuf::int32 value) {
  
  uid_ = value;
  // @@protoc_insertion_point(field_set:CommonRequest.uid)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ResponseHeader::kIdFieldNumber;
const int ResponseHeader::kTypeFieldNumber;
const int ResponseHeader::kFromFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ResponseHeader::ResponseHeader()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ResponseHeader)
}

void ResponseHeader::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

ResponseHeader::ResponseHeader(const ResponseHeader& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ResponseHeader)
}

void ResponseHeader::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0;
  type_ = 0;
  from_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

ResponseHeader::~ResponseHeader() {
  // @@protoc_insertion_point(destructor:ResponseHeader)
  SharedDtor();
}

void ResponseHeader::SharedDtor() {
  from_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void ResponseHeader::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ResponseHeader::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ResponseHeader_descriptor_;
}

const ResponseHeader& ResponseHeader::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Basic_2eproto();
  return *default_instance_;
}

ResponseHeader* ResponseHeader::default_instance_ = NULL;

ResponseHeader* ResponseHeader::New(::google::protobuf::Arena* arena) const {
  ResponseHeader* n = new ResponseHeader;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ResponseHeader::Clear() {
// @@protoc_insertion_point(message_clear_start:ResponseHeader)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(ResponseHeader, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<ResponseHeader*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(id_, type_);
  from_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());

#undef ZR_HELPER_
#undef ZR_

}

bool ResponseHeader::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ResponseHeader)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_type;
        break;
      }

      // optional int32 type = 2;
      case 2: {
        if (tag == 16) {
         parse_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &type_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_from;
        break;
      }

      // optional bytes from = 3;
      case 3: {
        if (tag == 26) {
         parse_from:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_from()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ResponseHeader)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ResponseHeader)
  return false;
#undef DO_
}

void ResponseHeader::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ResponseHeader)
  // optional int32 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional int32 type = 2;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->type(), output);
  }

  // optional bytes from = 3;
  if (this->from().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->from(), output);
  }

  // @@protoc_insertion_point(serialize_end:ResponseHeader)
}

::google::protobuf::uint8* ResponseHeader::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ResponseHeader)
  // optional int32 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional int32 type = 2;
  if (this->type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->type(), target);
  }

  // optional bytes from = 3;
  if (this->from().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->from(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:ResponseHeader)
  return target;
}

int ResponseHeader::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:ResponseHeader)
  int total_size = 0;

  // optional int32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  // optional int32 type = 2;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->type());
  }

  // optional bytes from = 3;
  if (this->from().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->from());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ResponseHeader::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ResponseHeader)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const ResponseHeader* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const ResponseHeader>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ResponseHeader)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ResponseHeader)
    MergeFrom(*source);
  }
}

void ResponseHeader::MergeFrom(const ResponseHeader& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ResponseHeader)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.type() != 0) {
    set_type(from.type());
  }
  if (from.from().size() > 0) {

    from_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.from_);
  }
}

void ResponseHeader::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ResponseHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ResponseHeader::CopyFrom(const ResponseHeader& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ResponseHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResponseHeader::IsInitialized() const {

  return true;
}

void ResponseHeader::Swap(ResponseHeader* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ResponseHeader::InternalSwap(ResponseHeader* other) {
  std::swap(id_, other->id_);
  std::swap(type_, other->type_);
  from_.Swap(&other->from_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ResponseHeader::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ResponseHeader_descriptor_;
  metadata.reflection = ResponseHeader_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ResponseHeader

// optional int32 id = 1;
void ResponseHeader::clear_id() {
  id_ = 0;
}
 ::google::protobuf::int32 ResponseHeader::id() const {
  // @@protoc_insertion_point(field_get:ResponseHeader.id)
  return id_;
}
 void ResponseHeader::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:ResponseHeader.id)
}

// optional int32 type = 2;
void ResponseHeader::clear_type() {
  type_ = 0;
}
 ::google::protobuf::int32 ResponseHeader::type() const {
  // @@protoc_insertion_point(field_get:ResponseHeader.type)
  return type_;
}
 void ResponseHeader::set_type(::google::protobuf::int32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:ResponseHeader.type)
}

// optional bytes from = 3;
void ResponseHeader::clear_from() {
  from_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& ResponseHeader::from() const {
  // @@protoc_insertion_point(field_get:ResponseHeader.from)
  return from_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void ResponseHeader::set_from(const ::std::string& value) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ResponseHeader.from)
}
 void ResponseHeader::set_from(const char* value) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ResponseHeader.from)
}
 void ResponseHeader::set_from(const void* value, size_t size) {
  
  from_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ResponseHeader.from)
}
 ::std::string* ResponseHeader::mutable_from() {
  
  // @@protoc_insertion_point(field_mutable:ResponseHeader.from)
  return from_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* ResponseHeader::release_from() {
  // @@protoc_insertion_point(field_release:ResponseHeader.from)
  
  return from_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void ResponseHeader::set_allocated_from(::std::string* from) {
  if (from != NULL) {
    
  } else {
    
  }
  from_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from);
  // @@protoc_insertion_point(field_set_allocated:ResponseHeader.from)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
