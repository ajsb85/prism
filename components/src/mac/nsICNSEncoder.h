/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Operating System Integration extension.
 *
 * The Initial Developer of the Original Code is
 * Matthew Gertner.
 * Portions created by the Initial Developer are Copyright (C) 2007
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Matthew Gertner <matthew.gertner@gmail.com> (Original author)
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

//#include <Carbon/Carbon.h>

//#include "IconFamily.h"

#include "imgIEncoder.h"
#include "nsINativeIcon.h"

#define NS_ICNSENCODER_CID \
{ /* 4de52056-a8d6-11dc-8314-0800200c9a66 */         \
     0x4de52056,                                     \
     0xa8d6,                                         \
     0x11dc,                                         \
    {0x83, 0x14, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66} \
}

// Provides ICNS encoding functionality. Use InitFromData() to do the
// encoding. See that function definition for encoding options.
class nsICNSEncoder : public imgIEncoder, public nsINativeIcon
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGIENCODER
  NS_DECL_NSIINPUTSTREAM
  NS_DECL_NSINATIVEICON

  nsICNSEncoder();

private:
  ~nsICNSEncoder();

protected:
  void* mIconFamily;
  void* mIconData;
  PRUint32 mIconSize;
  PRUint32 mReadPosition;
};
