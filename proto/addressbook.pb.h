// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: addressbook.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_addressbook_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_addressbook_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 3021000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 3021010 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_addressbook_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_addressbook_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_addressbook_2eproto;
namespace tutorial {
class AddressBook;
struct AddressBookDefaultTypeInternal;
extern AddressBookDefaultTypeInternal _AddressBook_default_instance_;
class Person;
struct PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
class Person_PhoneNumber;
struct Person_PhoneNumberDefaultTypeInternal;
extern Person_PhoneNumberDefaultTypeInternal _Person_PhoneNumber_default_instance_;
}  // namespace tutorial
PROTOBUF_NAMESPACE_OPEN
template <>
::tutorial::AddressBook* Arena::CreateMaybeMessage<::tutorial::AddressBook>(Arena*);
template <>
::tutorial::Person* Arena::CreateMaybeMessage<::tutorial::Person>(Arena*);
template <>
::tutorial::Person_PhoneNumber* Arena::CreateMaybeMessage<::tutorial::Person_PhoneNumber>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace tutorial {
enum Person_PhoneType : int {
  Person_PhoneType_MOBILE = 0,
  Person_PhoneType_HOME = 1,
  Person_PhoneType_WORK = 2,
};

bool Person_PhoneType_IsValid(int value);
constexpr Person_PhoneType Person_PhoneType_PhoneType_MIN = static_cast<Person_PhoneType>(0);
constexpr Person_PhoneType Person_PhoneType_PhoneType_MAX = static_cast<Person_PhoneType>(2);
constexpr int Person_PhoneType_PhoneType_ARRAYSIZE = 2 + 1;
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
Person_PhoneType_descriptor();
template <typename T>
const std::string& Person_PhoneType_Name(T value) {
  static_assert(std::is_same<T, Person_PhoneType>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to PhoneType_Name().");
  return Person_PhoneType_Name(static_cast<Person_PhoneType>(value));
}
template <>
inline const std::string& Person_PhoneType_Name(Person_PhoneType value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfDenseEnum<Person_PhoneType_descriptor,
                                                 0, 2>(
      static_cast<int>(value));
}
inline bool Person_PhoneType_Parse(absl::string_view name, Person_PhoneType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Person_PhoneType>(
      Person_PhoneType_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class Person_PhoneNumber final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tutorial.Person.PhoneNumber) */ {
 public:
  inline Person_PhoneNumber() : Person_PhoneNumber(nullptr) {}
  ~Person_PhoneNumber() override;
  explicit PROTOBUF_CONSTEXPR Person_PhoneNumber(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Person_PhoneNumber(const Person_PhoneNumber& from);
  Person_PhoneNumber(Person_PhoneNumber&& from) noexcept
    : Person_PhoneNumber() {
    *this = ::std::move(from);
  }

  inline Person_PhoneNumber& operator=(const Person_PhoneNumber& from) {
    CopyFrom(from);
    return *this;
  }
  inline Person_PhoneNumber& operator=(Person_PhoneNumber&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Person_PhoneNumber& default_instance() {
    return *internal_default_instance();
  }
  static inline const Person_PhoneNumber* internal_default_instance() {
    return reinterpret_cast<const Person_PhoneNumber*>(
               &_Person_PhoneNumber_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Person_PhoneNumber& a, Person_PhoneNumber& b) {
    a.Swap(&b);
  }
  inline void Swap(Person_PhoneNumber* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Person_PhoneNumber* other) {
    if (other == this) return;
    GOOGLE_ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Person_PhoneNumber* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Person_PhoneNumber>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Person_PhoneNumber& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Person_PhoneNumber& from) {
    Person_PhoneNumber::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Person_PhoneNumber* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tutorial.Person.PhoneNumber";
  }
  protected:
  explicit Person_PhoneNumber(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNumberFieldNumber = 1,
    kTypeFieldNumber = 2,
  };
  // optional string number = 1;
  bool has_number() const;
  void clear_number();
  const std::string& number() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_number(ArgT0&& arg0, ArgT... args);
  std::string* mutable_number();
  PROTOBUF_NODISCARD std::string* release_number();
  void set_allocated_number(std::string* number);
  private:
  const std::string& _internal_number() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_number(const std::string& value);
  std::string* _internal_mutable_number();
  public:

  // optional .tutorial.Person.PhoneType type = 2 [default = HOME];
  bool has_type() const;
  void clear_type();
  ::tutorial::Person_PhoneType type() const;
  void set_type(::tutorial::Person_PhoneType value);
  private:
  ::tutorial::Person_PhoneType _internal_type() const;
  void _internal_set_type(::tutorial::Person_PhoneType value);
  public:

  // @@protoc_insertion_point(class_scope:tutorial.Person.PhoneNumber)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr number_;
    int type_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_addressbook_2eproto;
};// -------------------------------------------------------------------

class Person final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tutorial.Person) */ {
 public:
  inline Person() : Person(nullptr) {}
  ~Person() override;
  explicit PROTOBUF_CONSTEXPR Person(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Person(const Person& from);
  Person(Person&& from) noexcept
    : Person() {
    *this = ::std::move(from);
  }

  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }
  inline Person& operator=(Person&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Person& default_instance() {
    return *internal_default_instance();
  }
  static inline const Person* internal_default_instance() {
    return reinterpret_cast<const Person*>(
               &_Person_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Person& a, Person& b) {
    a.Swap(&b);
  }
  inline void Swap(Person* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Person* other) {
    if (other == this) return;
    GOOGLE_ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Person* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Person>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Person& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Person& from) {
    Person::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Person* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tutorial.Person";
  }
  protected:
  explicit Person(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Person_PhoneNumber PhoneNumber;

  using PhoneType = Person_PhoneType;
  static constexpr PhoneType MOBILE = Person_PhoneType_MOBILE;
  static constexpr PhoneType HOME = Person_PhoneType_HOME;
  static constexpr PhoneType WORK = Person_PhoneType_WORK;
  static inline bool PhoneType_IsValid(int value) {
    return Person_PhoneType_IsValid(value);
  }
  static constexpr PhoneType PhoneType_MIN = Person_PhoneType_PhoneType_MIN;
  static constexpr PhoneType PhoneType_MAX = Person_PhoneType_PhoneType_MAX;
  static constexpr int PhoneType_ARRAYSIZE = Person_PhoneType_PhoneType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PhoneType_descriptor() {
    return Person_PhoneType_descriptor();
  }
  template <typename T>
  static inline const std::string& PhoneType_Name(T value) {
    return Person_PhoneType_Name(value);
  }
  static inline bool PhoneType_Parse(absl::string_view name, PhoneType* value) {
    return Person_PhoneType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kPhonesFieldNumber = 4,
    kNameFieldNumber = 1,
    kEmailFieldNumber = 3,
    kIdFieldNumber = 2,
  };
  // repeated .tutorial.Person.PhoneNumber phones = 4;
  int phones_size() const;
  private:
  int _internal_phones_size() const;
  public:
  void clear_phones();
  ::tutorial::Person_PhoneNumber* mutable_phones(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person_PhoneNumber >*
      mutable_phones();
  private:
  const ::tutorial::Person_PhoneNumber& _internal_phones(int index) const;
  ::tutorial::Person_PhoneNumber* _internal_add_phones();
  public:
  const ::tutorial::Person_PhoneNumber& phones(int index) const;
  ::tutorial::Person_PhoneNumber* add_phones();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person_PhoneNumber >&
      phones() const;

  // optional string name = 1;
  bool has_name() const;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // optional string email = 3;
  bool has_email() const;
  void clear_email();
  const std::string& email() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_email(ArgT0&& arg0, ArgT... args);
  std::string* mutable_email();
  PROTOBUF_NODISCARD std::string* release_email();
  void set_allocated_email(std::string* email);
  private:
  const std::string& _internal_email() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_email(const std::string& value);
  std::string* _internal_mutable_email();
  public:

  // optional int32 id = 2;
  bool has_id() const;
  void clear_id();
  ::int32_t id() const;
  void set_id(::int32_t value);
  private:
  ::int32_t _internal_id() const;
  void _internal_set_id(::int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:tutorial.Person)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person_PhoneNumber > phones_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr email_;
    ::int32_t id_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_addressbook_2eproto;
};// -------------------------------------------------------------------

class AddressBook final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tutorial.AddressBook) */ {
 public:
  inline AddressBook() : AddressBook(nullptr) {}
  ~AddressBook() override;
  explicit PROTOBUF_CONSTEXPR AddressBook(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  AddressBook(const AddressBook& from);
  AddressBook(AddressBook&& from) noexcept
    : AddressBook() {
    *this = ::std::move(from);
  }

  inline AddressBook& operator=(const AddressBook& from) {
    CopyFrom(from);
    return *this;
  }
  inline AddressBook& operator=(AddressBook&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const AddressBook& default_instance() {
    return *internal_default_instance();
  }
  static inline const AddressBook* internal_default_instance() {
    return reinterpret_cast<const AddressBook*>(
               &_AddressBook_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(AddressBook& a, AddressBook& b) {
    a.Swap(&b);
  }
  inline void Swap(AddressBook* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(AddressBook* other) {
    if (other == this) return;
    GOOGLE_ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  AddressBook* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<AddressBook>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const AddressBook& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const AddressBook& from) {
    AddressBook::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AddressBook* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "tutorial.AddressBook";
  }
  protected:
  explicit AddressBook(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPeopleFieldNumber = 1,
  };
  // repeated .tutorial.Person people = 1;
  int people_size() const;
  private:
  int _internal_people_size() const;
  public:
  void clear_people();
  ::tutorial::Person* mutable_people(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person >*
      mutable_people();
  private:
  const ::tutorial::Person& _internal_people(int index) const;
  ::tutorial::Person* _internal_add_people();
  public:
  const ::tutorial::Person& people(int index) const;
  ::tutorial::Person* add_people();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person >&
      people() const;

  // @@protoc_insertion_point(class_scope:tutorial.AddressBook)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person > people_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_addressbook_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Person_PhoneNumber

// optional string number = 1;
inline bool Person_PhoneNumber::has_number() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Person_PhoneNumber::clear_number() {
  _impl_.number_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Person_PhoneNumber::number() const {
  // @@protoc_insertion_point(field_get:tutorial.Person.PhoneNumber.number)
  return _internal_number();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Person_PhoneNumber::set_number(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.number_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:tutorial.Person.PhoneNumber.number)
}
inline std::string* Person_PhoneNumber::mutable_number() {
  std::string* _s = _internal_mutable_number();
  // @@protoc_insertion_point(field_mutable:tutorial.Person.PhoneNumber.number)
  return _s;
}
inline const std::string& Person_PhoneNumber::_internal_number() const {
  return _impl_.number_.Get();
}
inline void Person_PhoneNumber::_internal_set_number(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.number_.Set(value, GetArenaForAllocation());
}
inline std::string* Person_PhoneNumber::_internal_mutable_number() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.number_.Mutable(GetArenaForAllocation());
}
inline std::string* Person_PhoneNumber::release_number() {
  // @@protoc_insertion_point(field_release:tutorial.Person.PhoneNumber.number)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.number_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.number_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Person_PhoneNumber::set_allocated_number(std::string* number) {
  if (number != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.number_.SetAllocated(number, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.number_.IsDefault()) {
    _impl_.number_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:tutorial.Person.PhoneNumber.number)
}

// optional .tutorial.Person.PhoneType type = 2 [default = HOME];
inline bool Person_PhoneNumber::has_type() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void Person_PhoneNumber::clear_type() {
  _impl_.type_ = 1;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::tutorial::Person_PhoneType Person_PhoneNumber::_internal_type() const {
  return static_cast< ::tutorial::Person_PhoneType >(_impl_.type_);
}
inline ::tutorial::Person_PhoneType Person_PhoneNumber::type() const {
  // @@protoc_insertion_point(field_get:tutorial.Person.PhoneNumber.type)
  return _internal_type();
}
inline void Person_PhoneNumber::_internal_set_type(::tutorial::Person_PhoneType value) {
  assert(::tutorial::Person_PhoneType_IsValid(value));
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.type_ = value;
}
inline void Person_PhoneNumber::set_type(::tutorial::Person_PhoneType value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:tutorial.Person.PhoneNumber.type)
}

// -------------------------------------------------------------------

// Person

// optional string name = 1;
inline bool Person::has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Person::clear_name() {
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Person::name() const {
  // @@protoc_insertion_point(field_get:tutorial.Person.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Person::set_name(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:tutorial.Person.name)
}
inline std::string* Person::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:tutorial.Person.name)
  return _s;
}
inline const std::string& Person::_internal_name() const {
  return _impl_.name_.Get();
}
inline void Person::_internal_set_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* Person::_internal_mutable_name() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* Person::release_name() {
  // @@protoc_insertion_point(field_release:tutorial.Person.name)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.name_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Person::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:tutorial.Person.name)
}

// optional int32 id = 2;
inline bool Person::has_id() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void Person::clear_id() {
  _impl_.id_ = 0;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline ::int32_t Person::_internal_id() const {
  return _impl_.id_;
}
inline ::int32_t Person::id() const {
  // @@protoc_insertion_point(field_get:tutorial.Person.id)
  return _internal_id();
}
inline void Person::_internal_set_id(::int32_t value) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.id_ = value;
}
inline void Person::set_id(::int32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:tutorial.Person.id)
}

// optional string email = 3;
inline bool Person::has_email() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void Person::clear_email() {
  _impl_.email_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Person::email() const {
  // @@protoc_insertion_point(field_get:tutorial.Person.email)
  return _internal_email();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Person::set_email(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000002u;
 _impl_.email_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:tutorial.Person.email)
}
inline std::string* Person::mutable_email() {
  std::string* _s = _internal_mutable_email();
  // @@protoc_insertion_point(field_mutable:tutorial.Person.email)
  return _s;
}
inline const std::string& Person::_internal_email() const {
  return _impl_.email_.Get();
}
inline void Person::_internal_set_email(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.email_.Set(value, GetArenaForAllocation());
}
inline std::string* Person::_internal_mutable_email() {
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.email_.Mutable(GetArenaForAllocation());
}
inline std::string* Person::release_email() {
  // @@protoc_insertion_point(field_release:tutorial.Person.email)
  if ((_impl_._has_bits_[0] & 0x00000002u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* p = _impl_.email_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.email_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Person::set_allocated_email(std::string* email) {
  if (email != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.email_.SetAllocated(email, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.email_.IsDefault()) {
    _impl_.email_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:tutorial.Person.email)
}

// repeated .tutorial.Person.PhoneNumber phones = 4;
inline int Person::_internal_phones_size() const {
  return _impl_.phones_.size();
}
inline int Person::phones_size() const {
  return _internal_phones_size();
}
inline void Person::clear_phones() {
  _impl_.phones_.Clear();
}
inline ::tutorial::Person_PhoneNumber* Person::mutable_phones(int index) {
  // @@protoc_insertion_point(field_mutable:tutorial.Person.phones)
  return _impl_.phones_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person_PhoneNumber >*
Person::mutable_phones() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.Person.phones)
  return &_impl_.phones_;
}
inline const ::tutorial::Person_PhoneNumber& Person::_internal_phones(int index) const {
  return _impl_.phones_.Get(index);
}
inline const ::tutorial::Person_PhoneNumber& Person::phones(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.Person.phones)
  return _internal_phones(index);
}
inline ::tutorial::Person_PhoneNumber* Person::_internal_add_phones() {
  return _impl_.phones_.Add();
}
inline ::tutorial::Person_PhoneNumber* Person::add_phones() {
  ::tutorial::Person_PhoneNumber* _add = _internal_add_phones();
  // @@protoc_insertion_point(field_add:tutorial.Person.phones)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person_PhoneNumber >&
Person::phones() const {
  // @@protoc_insertion_point(field_list:tutorial.Person.phones)
  return _impl_.phones_;
}

// -------------------------------------------------------------------

// AddressBook

// repeated .tutorial.Person people = 1;
inline int AddressBook::_internal_people_size() const {
  return _impl_.people_.size();
}
inline int AddressBook::people_size() const {
  return _internal_people_size();
}
inline void AddressBook::clear_people() {
  _impl_.people_.Clear();
}
inline ::tutorial::Person* AddressBook::mutable_people(int index) {
  // @@protoc_insertion_point(field_mutable:tutorial.AddressBook.people)
  return _impl_.people_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person >*
AddressBook::mutable_people() {
  // @@protoc_insertion_point(field_mutable_list:tutorial.AddressBook.people)
  return &_impl_.people_;
}
inline const ::tutorial::Person& AddressBook::_internal_people(int index) const {
  return _impl_.people_.Get(index);
}
inline const ::tutorial::Person& AddressBook::people(int index) const {
  // @@protoc_insertion_point(field_get:tutorial.AddressBook.people)
  return _internal_people(index);
}
inline ::tutorial::Person* AddressBook::_internal_add_people() {
  return _impl_.people_.Add();
}
inline ::tutorial::Person* AddressBook::add_people() {
  ::tutorial::Person* _add = _internal_add_people();
  // @@protoc_insertion_point(field_add:tutorial.AddressBook.people)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::tutorial::Person >&
AddressBook::people() const {
  // @@protoc_insertion_point(field_list:tutorial.AddressBook.people)
  return _impl_.people_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace tutorial


PROTOBUF_NAMESPACE_OPEN

template <>
struct is_proto_enum<::tutorial::Person_PhoneType> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::tutorial::Person_PhoneType>() {
  return ::tutorial::Person_PhoneType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_addressbook_2eproto_2epb_2eh