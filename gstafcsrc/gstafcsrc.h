/* This file is part of Clementine.

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __GST_AFCSRC_H__
#define __GST_AFCSRC_H__

#include <gst/gst.h>
#include <gst/base/gstbasesrc.h>

#include <libimobiledevice/afc.h>
#include <libimobiledevice/libimobiledevice.h>
#include <libimobiledevice/lockdown.h>

G_BEGIN_DECLS

#define GST_TYPE_AFCSRC \
  (gst_afc_src_get_type())
#define GST_AFCSRC(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_AFCSRC,GstAfcSrc))
#define GST_AFCSRC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_AFCSRC,GstAfcSrcClass))
#define GST_IS_AFCSRC(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_AFCSRC))
#define GST_IS_AFCSRC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_AFCSRC))

typedef struct _GstAfcSrc      GstAfcSrc;
typedef struct _GstAfcSrcClass GstAfcSrcClass;

struct _GstAfcSrc {
  GstBaseSrc element;

  char* uuid_;
  char* path_;

  idevice_t device_;
  lockdownd_client_t lockdown_;
  afc_client_t afc_;

  uint16_t afc_port_;

  uint64_t file_handle_;
};

struct _GstAfcSrcClass {
  GstBaseSrcClass parent_class;
};

GType gst_afc_src_get_type (void);

G_END_DECLS

#endif
