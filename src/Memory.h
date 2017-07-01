#pragma once

#include "libretro/Core.h"

#include "imgui/imgui.h"

#include <stdio.h>
#include <string>
#include <vector>

class Memory
{
public:
  bool init(libretro::Core* core);
  void destroy();
  void draw(bool running);

  void reset();

protected:
  struct Region
  {
    std::string  _description;
    void*        _contents;
    size_t       _size;
    size_t       _baseAddr;
  };

  struct Block
  {
    unsigned    _memid;
    size_t      _start;
    size_t      _size;
    const char* _identifier;
    const char* _description;
  };

  bool initWidthMmap(const Block* block);
  bool initWidthMdata(const Block* block);

  bool initNES();
  bool initSNES();
  bool initSMS();
  bool initMD();

  libretro::Core* _core;
  int             _region;
  int             _platform;

  std::vector<Region> _regions;
};
