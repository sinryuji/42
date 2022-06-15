<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'b2br' );

/** Database username */
define( 'DB_USER', 'hyeongki' );

/** Database password */
define( 'DB_PASSWORD', 'rhldks1597159' );

/** Database hostname */
define( 'DB_HOST', 'localhost' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'VVxP6sSfWX_WzPjl|0k(;^wwL>Bv/sRgO%%}x3u6vfk$|p8u][I_OFUR Idh,Ekz' );
define( 'SECURE_AUTH_KEY',  '4dP$)&`G(TtA+i0n:i]({P~I=CVb2hn3-lQ^U5s?|D+{.,tq0:GfIbQis<.%0)i2' );
define( 'LOGGED_IN_KEY',    '2vbWd,vK-F$Oko{ugw`,vJ;.1znDf7Y$,CtwdTH qY:kEwumcFQ:Xf1YoC?q2PwS' );
define( 'NONCE_KEY',        'wC{eGN,TJ`8(Wk(E@Nm3l#eWP@ZLy/W=^&DF-2NPCQQ:f;t;V/&T7<r3,(+AhjRP' );
define( 'AUTH_SALT',        '@c`CE.}~D ~Y*]3SFRi:{?y+:y7B%k5/(po9RA|S6pao>*zE@#Ot6oNW~NhH0pcG' );
define( 'SECURE_AUTH_SALT', '`HlDkM$tD#,jj&sg,pK8&Gn5pCZjP7,ENNyUd%E_A,l:s?,}U^Q+PH--=nI *vl4' );
define( 'LOGGED_IN_SALT',   'JFfQXRMwi@2ml^nDi- e@X`a&4SKLPYu:UT?W`5X7Nl%`GZ5D%H&D;joZ~](JDXE' );
define( 'NONCE_SALT',       '6i~rx@-kt^uSS:dL._9{<a=,tVLB_4hX`WHz(2wT]3u*VE)E?x))Af,o)PZD(l#2' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
