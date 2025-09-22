#pragma once 

#include <ctypes>

namespace core {
class IFile {
public:
  enum class Origin {
    Begin,
    End,
    Set
  }
  // Open file mode
  enum class FileMode : uint8_t {
    Read = (1 << 0),
    Write = (1 << 1),
    ReadWrite = Read | Write,
    Append = (1 << 2),
    Truncate = (1 << 3)
  };

  IFile() = default;
  virtual ~IFile() = default;

  virtual const FileInfo& GetFileInfo() const = 0;
  virtual uint64_t Size() = 0;

  // IsReadOnly()

  virtual void Open(FileMode mode) = 0;
  virtual void Close() = 0;

  virtual bool IsOpened() const = 0;
  
  virtual uint64_t Seek(uint64_t offset, Origin origin) = 0;


  // This method returns offset in file 
  virtual uint64_t Tell() = 0;
  
  virtual uint64_t Read(uint8_t* buffer, uint64_t size) = 0;
  virtual uint64_t Write(const uint8_t* buffer, uint64_t size) = 0;


  // Templated read/write
  template<typename T>
  bool Read(T& value) {
    return (Read(reinterpret_cast<uint8_t*>(&value), sizeof(value)));
  }
  template<typename T>
  bool Write(const T& value) {
    return (Write(reinterpret_cast<const uint8_t>(&value), sizeof(value)));
  }


  // Vector read/write
  virtual uint64_t Read(std::vector<uint8_t>& buffer) = 0;
  virtual uint64_t Write(const std::vector<uint8_t>& buffer) = 0;

  // Stream read/write
  virtual uint64_t Read(std::ostream& stream, uint64_t size, uint64_t bufferSize = 1024) = 0;
  virtual uint64_t Write(std::istream& stream, uint64_t size, uint64_t bufferSize = 1024) = 0;

} // class IFile
  //
  //
  // TODO:
  // 1. Operator overloading 
  // For FileMode | & ^ ~
  //
  bool operator==(std::shared_ptr<class IFile> f1, std::shared_ptr<class IFile> f2) {
    if(!f1 || !f2) {
      return false;
    }

    return f1->GetFileInfo() == f2->GetFileInfo();
  }

} // namespace filesystem
