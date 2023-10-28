UENUM(BlueprintType)
enum class channel_type : uint8 {
	CHANNEL_TEXT		= 0,	//!< a text channel within a server
	DM			= 1,	//!< a direct message between users
	CHANNEL_VOICE		= 2,	//!< a voice channel within a server
	/**
	 * @brief a direct message between multiple users
	 * @deprecated this channel type was intended to be used with the now deprecated GameBridge SDK. Existing group dms with bots will continue to function, but newly created channels will be unusable
	 */
	GROUP_DM		= 3,
	CHANNEL_CATEGORY	= 4,	//!< an organizational category that contains up to 50 channels
	CHANNEL_ANNOUNCEMENT	= 5,	//!< a channel that users can follow and crosspost into their own server
	/**
	 * @brief a channel in which game developers can sell their game on Discord
	 * @deprecated store channels are deprecated by Discord
	 */
	CHANNEL_STORE		= 6,
	CHANNEL_ANNOUNCEMENT_THREAD	= 10,	//!< a temporary sub-channel within a GUILD_ANNOUNCEMENT channel
	CHANNEL_PUBLIC_THREAD	= 11,	//!< a temporary sub-channel within a GUILD_TEXT or GUILD_FORUM channel
	CHANNEL_PRIVATE_THREAD	= 12,	//!< a temporary sub-channel within a GUILD_TEXT channel that is only viewable by those invited and those with the MANAGE_THREADS permission
	CHANNEL_STAGE		= 13,	//!< a "stage" channel, like a voice channel with one authorised speaker
	CHANNEL_DIRECTORY	= 14,   //!< the channel in a [hub](https://support.discord.com/hc/en-us/articles/4406046651927-Discord-Student-Hubs-FAQ) containing the listed servers
	CHANNEL_FORUM		= 15,	//!< forum channel that can only contain threads
	CHANNEL_MEDIA		= 16,	//!< Media channel that can only contain threads, similar to forum channels
};

UENUM(BlueprintType)
enum class channel_flags : uint16 {
	/* Note that bits 1 to 4 are used for the channel type mask */
	/// NSFW Gated Channel
	c_nsfw =		0b0000000000010000,
	/// Video quality forced to 720p
	c_video_quality_720p =	0b0000000000100000,
	/// Lock permissions (only used when updating channel positions)
	c_lock_permissions =	0b0000000001000000,
	/// Thread is pinned to the top of its parent forum or media channel
	c_pinned_thread =	0b0000000010000000,
	/// Whether a tag is required to be specified when creating a thread in a forum or a media channel. Tags are specified in the thread::applied_tags field.
	c_require_tag =		0b0000000100000000,
	/* Note that the 9th and 10th bit are used for the forum layout type */
	/// When set hides the embedded media download options. Available only for media channels
	c_hide_media_download_options = 0b0001000000000000,
};

UENUM(BlueprintType)
enum class default_forum_sort_order_t : uint8 {
	/// Sort forum posts by activity (default)
	so_latest_activity = 0,
	/// Sort forum posts by creation time (from most recent to oldest)
	so_creation_date = 1,
};

UENUM(BlueprintType)
enum class forum_layout_type : uint8 {
	fl_not_set = 0, //!< No default has been set for the forum channel
	fl_list_view = 1, //!< Display posts as a list
	fl_gallery_view = 2, //!< Display posts as a collection of tiles
};

UENUM(BlueprintType)
enum class overwrite_type : uint8 {
	/// Role
	ot_role = 0,
	/// Member
	ot_member = 1
};

UENUM(BlueprintType)
enum class auto_archive_duration_t : uint8 {
	/// Auto archive duration of 1 hour. (60 minutes)
	arc_1_hour = 1,
	/// Auto archive duration of 1 day. (1440 minutes)
	arc_1_day = 2,
	/// Auto archive duration of 3 days. (4320 minutes)
	arc_3_days = 3,
	/// Auto archive duration of 1 week. (10080 minutes)
	arc_1_week = 4,
};

