#include "libnotify_notification.h"

#include <libnotify/notify.h>

void send_notification(const char* summary, const char* body, const char* icon) {
	notify_init("janot");
	NotifyNotification* notification = notify_notification_new(summary, body, icon);
	notify_notification_show(notification, NULL);
	g_object_unref(G_OBJECT(notification));
	notify_uninit();
}
