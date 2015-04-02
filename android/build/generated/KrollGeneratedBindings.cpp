/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /private/var/folders/hc/19hq28_941d4h7wx_qj406vr0000gn/T/dieskim/titanium-countly-android-messaging-generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/private/var/folders/hc/19hq28_941d4h7wx_qj406vr0000gn/T/dieskim/titanium-countly-android-messaging-generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "count.ly.messaging.TitaniumCountlyAndroidMessagingModule.h"
#include "count.ly.messaging.ExampleProxy.h"


#line 14 "/private/var/folders/hc/19hq28_941d4h7wx_qj406vr0000gn/T/dieskim/titanium-countly-android-messaging-generated/KrollGeneratedBindings.gperf"
struct titanium::bindings::BindEntry;
/* maximum key range = 26, duplicates = 0 */

class TitaniumCountlyAndroidMessagingBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct titanium::bindings::BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
TitaniumCountlyAndroidMessagingBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct titanium::bindings::BindEntry *
TitaniumCountlyAndroidMessagingBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 2,
      MIN_WORD_LENGTH = 31,
      MAX_WORD_LENGTH = 56,
      MIN_HASH_VALUE = 31,
      MAX_HASH_VALUE = 56
    };

  static struct titanium::bindings::BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 17 "/private/var/folders/hc/19hq28_941d4h7wx_qj406vr0000gn/T/dieskim/titanium-countly-android-messaging-generated/KrollGeneratedBindings.gperf"
      {"count.ly.messaging.ExampleProxy", ::count::ly::messaging::titaniumcountlyandroidmessaging::ExampleProxy::bindProxy, ::count::ly::messaging::titaniumcountlyandroidmessaging::ExampleProxy::dispose},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 16 "/private/var/folders/hc/19hq28_941d4h7wx_qj406vr0000gn/T/dieskim/titanium-countly-android-messaging-generated/KrollGeneratedBindings.gperf"
      {"count.ly.messaging.TitaniumCountlyAndroidMessagingModule", ::count::ly::messaging::TitaniumCountlyAndroidMessagingModule::bindProxy, ::count::ly::messaging::TitaniumCountlyAndroidMessagingModule::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 18 "/private/var/folders/hc/19hq28_941d4h7wx_qj406vr0000gn/T/dieskim/titanium-countly-android-messaging-generated/KrollGeneratedBindings.gperf"

