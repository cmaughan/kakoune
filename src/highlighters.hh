#ifndef highlighters_hh_INCLUDED
#define highlighters_hh_INCLUDED

#include "color.hh"
#include "highlighter.hh"
#include "option.hh"

namespace Kakoune
{

void register_highlighters();

struct InclusiveBufferRange{ BufferCoord first, last; };

inline bool operator==(const InclusiveBufferRange& lhs, const InclusiveBufferRange& rhs)
{
    return lhs.first == rhs.first and lhs.last == rhs.last;
}
String option_to_string(InclusiveBufferRange range);
void option_from_string(StringView str, InclusiveBufferRange& opt);

using LineAndSpec = std::tuple<LineCount, String>;
using LineAndSpecList = TimestampedList<LineAndSpec>;

constexpr StringView option_type_name(Meta::Type<LineAndSpecList>)
{
    return "line-specs";
}
void option_update(LineAndSpecList& opt, const Context& context);

using RangeAndString = std::tuple<InclusiveBufferRange, String>;
using RangeAndStringList = TimestampedList<RangeAndString>;

constexpr StringView option_type_name(Meta::Type<RangeAndStringList>)
{
    return "range-specs";
}
void option_update(RangeAndStringList& opt, const Context& context);

}

#endif // highlighters_hh_INCLUDED
