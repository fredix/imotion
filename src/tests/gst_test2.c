
 #include <gtk/gtk.h>
 #include <gst/gst.h>
 #include <gst/gst.h>
 #include <gst/base/gstbasesrc.h>


 #define PUT_IN_BIN
 #define V4L2SRC

 int main(int argc, char **argv)
 {
   GstElement *pipeline;
   GstElement *bin;
   gboolean ok;

   GstElement *video_source;

   GstElement *csp;
   GstElement *video_sink;

   gtk_init(&argc, &argv);
   gst_init (&argc, &argv);


   pipeline = gst_pipeline_new ("pipeline");
   bin = gst_bin_new ("bin");

 #ifdef V4L2SRC
   video_source = gst_element_factory_make ("v4l2src", "video_src");
 #else
   video_source = gst_element_factory_make ("videotestsrc", "video_source");
 #endif

   csp = gst_element_factory_make ("ffmpegcolorspace", "csp");
   video_sink = gst_element_factory_make ("ximagesink", "video_sink");

 #ifdef PUT_IN_BIN
   gst_bin_add_many (GST_BIN (bin), video_source, csp, video_sink, NULL);
   gst_bin_add_many (GST_BIN (pipeline), bin, NULL);
 #else
   gst_bin_add_many (GST_BIN (pipeline), video_source, csp, video_sink, NULL);
 #endif
   ok = gst_element_link_many (video_source, csp, video_sink, NULL);

   gst_element_set_state (pipeline, GST_STATE_PLAYING);

   gtk_main();
   return 0;
 }
