#ifndef __LINUX_MSM_CAM_SENSOR_H
#define __LINUX_MSM_CAM_SENSOR_H

#ifdef MSM_CAMERA_BIONIC
#include <sys/types.h>
#endif
#include <linux/types.h>
#include <linux/v4l2-mediabus.h>
#include <linux/i2c.h>

#define I2C_SEQ_REG_SETTING_MAX   5
#define I2C_SEQ_REG_DATA_MAX      256
#define I2C_REG_DATA_MAX         (8*1024)
#define MAX_CID                   16

#define MSM_SENSOR_MCLK_8HZ   8000000
#define MSM_SENSOR_MCLK_16HZ  16000000
#define MSM_SENSOR_MCLK_24HZ  24000000

#define GPIO_OUT_LOW          (0 << 1)
#define GPIO_OUT_HIGH         (1 << 1)

#define CSI_EMBED_DATA        0x12
#define CSI_RESERVED_DATA_0   0x13
#define CSI_YUV422_8          0x1E
#define CSI_RAW8              0x2A
#define CSI_RAW10             0x2B
#define CSI_RAW12             0x2C

#define CSI_DECODE_6BIT         0
#define CSI_DECODE_8BIT         1
#define CSI_DECODE_10BIT        2
#define CSI_DECODE_DPCM_10_8_10 5

#define MAX_SENSOR_NAME 32

#define MAX_ACT_MOD_NAME_SIZE 32
#define MAX_ACT_NAME_SIZE 32
#define NUM_ACTUATOR_DIR 2
#define MAX_ACTUATOR_SCENARIO 8
#define MAX_ACTUATOR_REGION 5
#define MAX_ACTUATOR_INIT_SET 50 //12
#define MAX_ACTUATOR_REG_TBL_SIZE 8
#define MAX_ACTUATOR_AF_TOTAL_STEPS 1024

#define MOVE_NEAR 0
#define MOVE_FAR  1

#define MSM_ACTUATOR_MOVE_SIGNED_FAR -1
#define MSM_ACTUATOR_MOVE_SIGNED_NEAR  1

#define MAX_EEPROM_NAME 32

#define MAX_AF_ITERATIONS 3
#define MAX_NUMBER_OF_STEPS 47

//************************************* Native functionalities for YUV sensor added by jai.prakash
#define EXT_CAM_EV			1
#define EXT_CAM_WB			2
#define EXT_CAM_METERING	3
#define EXT_CAM_ISO			4
#define EXT_CAM_EFFECT		5
#define EXT_CAM_SCENE_MODE	6
#define EXT_CAM_SENSOR_MODE	7
#define EXT_CAM_CONTRAST	8
#define EXT_CAM_EXIF		9
#define EXT_CAM_SET_AE_AWB	10
//Focus related enums
#define EXT_CAM_AF		11
#define EXT_CAM_FOCUS		12
#define EXT_CAM_SET_TOUCHAF_POS	13
#define EXT_CAM_SET_AF_STATUS	14
#define EXT_CAM_GET_AF_STATUS	15
#define EXT_CAM_GET_AF_RESULT	16
#define EXT_CAM_SET_AF_STOP	17
#define EXT_CAM_FLASH_MODE      18
#define EXT_CAM_SET_FLASH	19
#define EXT_CAM_VT_MODE		20
//Exposure Compensation
#define CAMERA_EV_M4		0
#define CAMERA_EV_M3		1
#define CAMERA_EV_M2		2
#define CAMERA_EV_M1		3
#define CAMERA_EV_DEFAULT	4
#define CAMERA_EV_P1		5
#define CAMERA_EV_P2		6
#define CAMERA_EV_P3		7
#define CAMERA_EV_P4		8

//White Balance
#define CAMERA_WHITE_BALANCE_OFF				0
#define CAMERA_WHITE_BALANCE_AUTO				1
#define CAMERA_WHITE_BALANCE_INCANDESCENT		2
#define CAMERA_WHITE_BALANCE_FLUORESCENT		3
#define CAMERA_WHITE_BALANCE_DAYLIGHT			5
#define CAMERA_WHITE_BALANCE_CLOUDY_DAYLIGHT	6

//Metering
#define CAMERA_AVERAGE			0
#define CAMERA_CENTER_WEIGHT	1
#define CAMERA_SPOT				2

//ISO
#define CAMERA_ISO_MODE_AUTO	0
#define CAMERA_ISO_MODE_50		1
#define CAMERA_ISO_MODE_100		2
#define CAMERA_ISO_MODE_200		3
#define CAMERA_ISO_MODE_400		4
#define CAMERA_ISO_MODE_800		5

//Effect
#define CAMERA_EFFECT_OFF			0
#define CAMERA_EFFECT_MONO			1
#define CAMERA_EFFECT_NEGATIVE		2
#define CAMERA_EFFECT_SOLARIZE		3
#define CAMERA_EFFECT_SEPIA			4
#define CAMERA_EFFECT_POSTERIZE		5
#define CAMERA_EFFECT_WHITEBOARD	6
#define CAMERA_EFFECT_BLACKBOARD	7
#define CAMERA_EFFECT_AQUA			8
#define CAMERA_EFFECT_EMBOSS		9
#define CAMERA_EFFECT_SKETCH		10
#define CAMERA_EFFECT_NEON			11
#define CAMERA_EFFECT_WASHED		12
#define CAMERA_EFFECT_VINTAGE_WARM	13
#define CAMERA_EFFECT_VINTAGE_COLD	14
#define CAMERA_EFFECT_POINT_COLOR_1	15
#define CAMERA_EFFECT_POINT_COLOR_2	16
#define CAMERA_EFFECT_POINT_COLOR_3	17
#define CAMERA_EFFECT_POINT_COLOR_4	18
#define CAMERA_EFFECT_CARTOONIZE	19
#define CAMERA_EFFECT_MAX			20

//scene mode
#define CAMERA_SCENE_AUTO		0
#define CAMERA_SCENE_LANDSCAPE		3
#define CAMERA_SCENE_SPORT		9
#define CAMERA_SCENE_PARTY		13
#define CAMERA_SCENE_BEACH		7
#define CAMERA_SCENE_SUNSET		12
#define CAMERA_SCENE_DAWN		21	//need to check
#define CAMERA_SCENE_FALL		17
#define CAMERA_SCENE_CANDLE		14
#define CAMERA_SCENE_FIRE		11
#define CAMERA_SCENE_AGAINST_LIGHT	16
#define CAMERA_SCENE_NIGHT		6

#define CAMERA_SCENE_PORTRAIT		8
#define CAMERA_SCENE_TEXT		19
//AF modes
#define CAMERA_AF_MACRO         2
#define CAMERA_AF_AUTO          0
#define CAMERA_AF_OCR           3


#define CAMERA_MODE_INIT                0
#define CAMERA_MODE_PREVIEW             1
#define CAMERA_MODE_CAPTURE             2
#define CAMERA_MODE_RECORDING           3

//Flash modes
#define CAMERA_FLASH_OFF	0
#define CAMERA_FLASH_ON		2
#define CAMERA_FLASH_AUTO	1
#define CAMERA_FLASH_TORCH	3

#define CAMERA_CONTRAST_LV0			0
#define CAMERA_CONTRAST_LV1			1
#define CAMERA_CONTRAST_LV2			2
#define CAMERA_CONTRAST_LV3			3
#define CAMERA_CONTRAST_LV4			4
#define CAMERA_CONTRAST_LV5			5
#define CAMERA_CONTRAST_LV6			6
#define CAMERA_CONTRAST_LV7			7
#define CAMERA_CONTRAST_LV8			8
#define CAMERA_CONTRAST_LV9			9

//**************************************

enum msm_camera_i2c_reg_addr_type {
	MSM_CAMERA_I2C_BYTE_ADDR = 1,
	MSM_CAMERA_I2C_WORD_ADDR,
	MSM_CAMERA_I2C_3B_ADDR,
	MSM_CAMERA_I2C_ADDR_TYPE_MAX,
};

enum msm_camera_i2c_data_type {
	MSM_CAMERA_I2C_BYTE_DATA = 1,
	MSM_CAMERA_I2C_WORD_DATA,
	MSM_CAMERA_I2C_SET_BYTE_MASK,
	MSM_CAMERA_I2C_UNSET_BYTE_MASK,
	MSM_CAMERA_I2C_SET_WORD_MASK,
	MSM_CAMERA_I2C_UNSET_WORD_MASK,
	MSM_CAMERA_I2C_SET_BYTE_WRITE_MASK_DATA,
	MSM_CAMERA_I2C_BURST_DATA,
	MSM_CAMERA_I2C_DATA_TYPE_MAX,
};

enum msm_sensor_power_seq_type_t {
	SENSOR_CLK,
	SENSOR_GPIO,
	SENSOR_VREG,
	SENSOR_I2C_MUX,
#if defined(CONFIG_MACH_MONTBLANC) || defined(MONTBLANC_CAMERA) || defined(CONFIG_MACH_VIKALCU) || defined(VIKAL_CAMERA)
	SENSOR_ADDITIONAL_LDO,
#endif
};

enum msm_sensor_clk_type_t {
	SENSOR_CAM_MCLK,
	SENSOR_CAM_CLK,
	SENSOR_CAM_CLK_MAX,
};

enum msm_sensor_power_seq_gpio_t {
	SENSOR_GPIO_RESET,
	SENSOR_GPIO_STANDBY,
	SENSOR_GPIO_VT_RESET,
	SENSOR_GPIO_VT_STANDBY,
	SENSOR_GPIO_EXT_VANA_POWER,
	SENSOR_GPIO_EXT_VIO_POWER,
	SENSOR_GPIO_EXT_CAMIO_EN,
	SENSOR_GPIO_EXT_VAF_POWER,
	SENSOR_GPIO_MIPI_CHANGE,
	SENSOR_GPIO_MAX,
};

enum msm_camera_vreg_name_t {
	CAM_VDIG,
	CAM_VIO,
	CAM_VAF,
	CAM_VANA,
	CAM_VREG_MAX,
};

enum msm_sensor_resolution_t {
	MSM_SENSOR_RES_FULL,
	MSM_SENSOR_RES_QTR,
	MSM_SENSOR_RES_2,
	MSM_SENSOR_RES_3,
	MSM_SENSOR_RES_4,
	MSM_SENSOR_RES_5,
	MSM_SENSOR_RES_6,
	MSM_SENSOR_RES_7,
	MSM_SENSOR_RES_8,
	MSM_SENSOR_RES_9,
	MSM_SENSOR_RES_10,
	MSM_SENSOR_RES_11,
	MSM_SENSOR_RES_12,
	MSM_SENSOR_RES_13,
	MSM_SENSOR_INVALID_RES,
};

enum sensor_sub_module_t {
	SUB_MODULE_SENSOR,
	SUB_MODULE_CHROMATIX,
	SUB_MODULE_ACTUATOR,
	SUB_MODULE_EEPROM,
	SUB_MODULE_LED_FLASH,
	SUB_MODULE_STROBE_FLASH,
	SUB_MODULE_CSIPHY,
	SUB_MODULE_CSIPHY_3D,
	SUB_MODULE_CSID,
	SUB_MODULE_CSID_3D,
	SUB_MODULE_MAX,
};

enum csid_cfg_type_t {
	CSID_INIT,
	CSID_CFG,
	CSID_RELEASE,
};

enum csiphy_cfg_type_t {
	CSIPHY_INIT,
	CSIPHY_CFG,
	CSIPHY_RELEASE,
};

enum camera_vreg_type {
	REG_LDO,
	REG_VS,
	REG_GPIO,
};

struct msm_sensor_gpio_config {
enum msm_sensor_power_seq_gpio_t gpio_name;
uint8_t config_val;
};

struct msm_sensor_power_setting {
	enum msm_sensor_power_seq_type_t seq_type;
	uint16_t seq_val;
	long config_val;
	uint16_t delay;
	void *data[10];
};

struct msm_sensor_power_setting_array {
	struct msm_sensor_power_setting *power_setting;
	uint16_t size;
	struct msm_sensor_power_setting *power_off_setting;
	uint16_t off_size;
};

struct msm_sensor_id_info_t {
	uint16_t sensor_id_reg_addr;
	uint16_t sensor_id;
};

enum msm_sensor_camera_id_t {
	CAMERA_0,
	CAMERA_1,
	CAMERA_2,
	CAMERA_3,
	MAX_CAMERAS,
};

enum cci_i2c_master_t {
	MASTER_0,
	MASTER_1,
	MASTER_MAX,
};

struct msm_sensor_info_t {
	char     sensor_name[MAX_SENSOR_NAME];
	int32_t  session_id;
	int32_t  subdev_id[SUB_MODULE_MAX];
	uint8_t  is_mount_angle_valid;
	uint32_t sensor_mount_angle;
};

struct msm_camera_sensor_slave_info {
	char sensor_name[32];
	enum msm_sensor_camera_id_t camera_id;
	uint16_t slave_addr;
	enum msm_camera_i2c_reg_addr_type addr_type;
	enum msm_camera_i2c_data_type data_type;
	struct msm_sensor_id_info_t sensor_id_info;
	struct msm_sensor_power_setting_array power_setting_array;
	uint8_t is_probe_succeed;
    char subdev_name[32];
	struct msm_sensor_info_t sensor_info;
};

struct msm_camera_i2c_reg_array {
	uint16_t reg_addr;
	uint16_t reg_data;
	uint32_t delay;
};

struct msm_camera_i2c_burst_reg_array {
	uint16_t reg_addr;
	uint8_t *reg_data;
	uint16_t reg_data_size;
};

struct msm_camera_i2c_reg_setting {
	void *reg_setting;
	uint16_t size;
	enum msm_camera_i2c_reg_addr_type addr_type;
	enum msm_camera_i2c_data_type data_type;
	uint16_t delay;
};

struct msm_camera_i2c_seq_reg_array {
	uint16_t reg_addr;
	uint8_t reg_data[I2C_SEQ_REG_DATA_MAX];
	uint16_t reg_data_size;
};

struct msm_camera_i2c_seq_reg_setting {
	struct msm_camera_i2c_seq_reg_array *reg_setting;
	uint16_t size;
	enum msm_camera_i2c_reg_addr_type addr_type;
	uint16_t delay;
};

struct msm_camera_i2c_read_config {
	uint16_t slave_addr;
	uint16_t reg_addr;
	enum msm_camera_i2c_data_type data_type;
	uint16_t *data;
};

struct msm_camera_csid_vc_cfg {
	uint8_t cid;
	uint8_t dt;
	uint8_t decode_format;
};

struct msm_camera_csid_lut_params {
	uint8_t num_cid;
	struct msm_camera_csid_vc_cfg *vc_cfg[MAX_CID];
};

struct msm_camera_csid_params {
	uint8_t lane_cnt;
	uint16_t lane_assign;
	uint8_t phy_sel;
	struct msm_camera_csid_lut_params lut_params;
};

struct msm_camera_csiphy_params {
	uint8_t lane_cnt;
	uint8_t settle_cnt;
	uint16_t lane_mask;
	uint8_t combo_mode;
	uint8_t csid_core;
};

struct msm_camera_csi2_params {
	struct msm_camera_csid_params csid_params;
	struct msm_camera_csiphy_params csiphy_params;
};

struct msm_camera_csi_lane_params {
	uint16_t csi_lane_assign;
	uint16_t csi_lane_mask;
};

struct csi_lane_params_t {
	uint16_t csi_lane_assign;
	uint8_t csi_lane_mask;
	uint8_t csi_if;
	uint8_t csid_core[2];
	uint8_t csi_phy_sel;
};

struct camera_vreg_t {
	const char *reg_name;
	enum camera_vreg_type type;
	int min_voltage;
	int max_voltage;
	int op_mode;
	uint32_t delay;
};

enum camb_position_t {
	BACK_CAMERA_B,
	FRONT_CAMERA_B,
};

enum camerab_mode_t {
	CAMERA_MODE_2D_B = (1<<0),
	CAMERA_MODE_3D_B = (1<<1)
};

struct sensorb_cfg_data {
	int cfgtype;
#if !defined(CONFIG_MACH_S3VE3G_EUR)
    int flicker_type;
#endif
	union {
		struct msm_sensor_info_t      sensor_info;
		void                         *setting;
	} cfg;
};

struct csid_cfg_data {
	enum csid_cfg_type_t cfgtype;
	union {
		uint32_t csid_version;
		struct msm_camera_csid_params *csid_params;
	} cfg;
};

struct csiphy_cfg_data {
	enum csiphy_cfg_type_t cfgtype;
	union {
		struct msm_camera_csiphy_params *csiphy_params;
		struct msm_camera_csi_lane_params *csi_lane_params;
	} cfg;
};

enum eeprom_cfg_type_t {
	CFG_EEPROM_GET_INFO,
	CFG_EEPROM_GET_CAL_DATA,
	CFG_EEPROM_READ_CAL_DATA,
	CFG_EEPROM_READ_DATA,
	CFG_EEPROM_READ_COMPRESSED_DATA,
	CFG_EEPROM_WRITE_DATA,
	CFG_EEPROM_GET_ERASESIZE,
	CFG_EEPROM_ERASE,
	CFG_EEPROM_POWER_ON,
	CFG_EEPROM_POWER_OFF,
	CFG_EEPROM_READ_DATA_FROM_HW,
};
struct eeprom_get_t {
	uint32_t num_bytes;
};

struct eeprom_read_t {
	uint8_t *dbuffer;
	uint32_t num_bytes;
	uint32_t addr;
	uint32_t comp_size;
};

struct eeprom_write_t {
	uint8_t *dbuffer;
	uint32_t num_bytes;
	uint32_t addr;
	uint32_t *write_size;
	uint8_t compress;
};

struct eeprom_erase_t {
	uint32_t num_bytes;
	uint32_t addr;
};

struct msm_eeprom_cfg_data {
	enum eeprom_cfg_type_t cfgtype;
	uint8_t is_supported;
	union {
		char eeprom_name[MAX_EEPROM_NAME];
		struct eeprom_get_t get_data;
		struct eeprom_read_t read_data;
		struct eeprom_write_t write_data;
		struct eeprom_erase_t erase_data;
	} cfg;
};

enum msm_sensor_cfg_type_t {
	CFG_SET_SLAVE_INFO,
	CFG_SLAVE_READ_I2C,
	CFG_WRITE_I2C_ARRAY,
	CFG_WRITE_I2C_SEQ_ARRAY,
	CFG_POWER_UP,
	CFG_POWER_DOWN,
	CFG_SET_STOP_STREAM_SETTING,
	CFG_GET_SENSOR_INFO,
	CFG_SET_INIT_SETTING,
	CFG_SET_RESOLUTION,
	CFG_SET_STOP_STREAM,
	CFG_SET_START_STREAM,
	CFG_SET_GPIO_STATE,
	CFG_SET_SENSOR_OTP_CAL, // Randy 10.08
};

enum msm_actuator_cfg_type_t {
	CFG_GET_ACTUATOR_INFO,
	CFG_SET_ACTUATOR_INFO,
	CFG_SET_DEFAULT_FOCUS,
        CFG_SET_POSITION,
	CFG_MOVE_FOCUS,
	CFG_SET_ACTUATOR_SW_LANDING,
};

enum actuator_type {
	ACTUATOR_VCM,
	ACTUATOR_PIEZO,
	ACTUATOR_HALL_EFFECT,
	ACTUATOR_HVCM,
	ACTUATOR_DW9804,
};

enum msm_actuator_data_type {
	MSM_ACTUATOR_BYTE_DATA = 1,
	MSM_ACTUATOR_WORD_DATA,
};

enum msm_actuator_addr_type {
	MSM_ACTUATOR_BYTE_ADDR = 1,
	MSM_ACTUATOR_WORD_ADDR,
};

struct reg_settings_t {
	uint16_t reg_addr;
	uint16_t reg_data;
};

struct region_params_t {
	/* [0] = ForwardDirection Macro boundary
	   [1] = ReverseDirection Inf boundary
        */
	uint16_t step_bound[2];
	uint16_t code_per_step;
};

struct damping_params_t {
	uint32_t damping_step;
	uint32_t damping_delay;
	uint32_t hw_params;
};

struct msm_actuator_move_params_t {
	int8_t dir;
	int8_t sign_dir;
	int16_t dest_step_pos;
	int32_t num_steps;
	struct damping_params_t *ringing_params;
};

struct msm_actuator_tuning_params_t {
	int16_t initial_code;
	uint16_t pwd_step;
	uint16_t region_size;
	uint32_t total_steps;
	struct region_params_t *region_params;
};

struct msm_actuator_params_t {
	enum actuator_type act_type;
	uint8_t reg_tbl_size;
	uint16_t data_size;
	uint16_t init_setting_size;
	uint32_t i2c_addr;
	enum msm_actuator_addr_type i2c_addr_type;
	enum msm_actuator_data_type i2c_data_type;
	struct msm_actuator_reg_params_t *reg_tbl_params;
	struct reg_settings_t *init_settings;
};

struct msm_actuator_set_info_t {
	struct msm_actuator_params_t actuator_params;
	struct msm_actuator_tuning_params_t af_tuning_params;
};

struct msm_actuator_get_info_t {
	uint32_t focal_length_num;
	uint32_t focal_length_den;
	uint32_t f_number_num;
	uint32_t f_number_den;
	uint32_t f_pix_num;
	uint32_t f_pix_den;
	uint32_t total_f_dist_num;
	uint32_t total_f_dist_den;
	uint32_t hor_view_angle_num;
	uint32_t hor_view_angle_den;
	uint32_t ver_view_angle_num;
	uint32_t ver_view_angle_den;
};

enum af_camera_name {
	ACTUATOR_MAIN_CAM_0,
	ACTUATOR_MAIN_CAM_1,
	ACTUATOR_MAIN_CAM_2,
	ACTUATOR_MAIN_CAM_3,
	ACTUATOR_MAIN_CAM_4,
	ACTUATOR_MAIN_CAM_5,
	ACTUATOR_WEB_CAM_0,
	ACTUATOR_WEB_CAM_1,
	ACTUATOR_WEB_CAM_2,
};


struct msm_actuator_set_position_t {
   uint16_t number_of_steps;
   uint16_t pos[MAX_NUMBER_OF_STEPS];
   uint16_t delay[MAX_NUMBER_OF_STEPS];
};

struct msm_actuator_cfg_data {
	int cfgtype;
	uint8_t is_af_supported;
	union {
		struct msm_actuator_move_params_t move;
		struct msm_actuator_set_info_t set_info;
		struct msm_actuator_get_info_t get_info;
                struct msm_actuator_set_position_t setpos;
		enum af_camera_name cam_name;
	} cfg;
};

enum msm_actuator_write_type {
	MSM_ACTUATOR_WRITE_HW_DAMP,
	MSM_ACTUATOR_WRITE_DAC,
	MSM_ACTUATOR_WRITE_DAC_SEQ,
};

enum msm_actuator_init_focus_type{
  MSM_ACTUATOR_INIT_FOCUS_DELAY = 0xDD,
  MSM_ACTUATOR_INIT_FOCUS_READ_STATUS = 0xDC,  
};

struct msm_actuator_reg_params_t {
	enum msm_actuator_write_type reg_write_type;
	uint32_t hw_mask;
	uint16_t reg_addr;
	uint16_t hw_shift;
	uint16_t data_shift;
};

enum msm_camera_led_config_t {
	MSM_CAMERA_LED_OFF,
	MSM_CAMERA_LED_LOW,
	MSM_CAMERA_LED_HIGH,
	MSM_CAMERA_LED_INIT,
	MSM_CAMERA_LED_RELEASE,
#if defined(CONFIG_MACH_VICTORLTE_CTC) || defined(CONFIG_SEC_MEGA2_PROJECT)
	MSM_CAMERA_LED_FACTORY = 8,
#endif
};

struct msm_camera_led_cfg_t {
	enum msm_camera_led_config_t cfgtype;
};

/* sensor init structures and enums */
enum msm_sensor_init_cfg_type_t {
	CFG_SINIT_PROBE,
};

struct sensor_init_cfg_data {
	enum msm_sensor_init_cfg_type_t cfgtype;
	union {
		void *setting;
	} cfg;
};

struct ioctl_native_cmd {
        unsigned short mode;
        unsigned short address;
        unsigned short value_1;
        unsigned short value_2;
        unsigned short value_3;
};

typedef struct
{
	unsigned short iso;
	unsigned short shutterspeed;
	unsigned short isFlashOn;
} exif_data_t;

enum msm_cam_flicker_type {
	MSM_CAM_FLICKER_50HZ,
	MSM_CAM_FLICKER_60HZ,
};

enum sensor_af_e {
	SENSOR_AF_CANCEL = 1,
	SENSOR_AF_START,
	SENSOR_AF_PRE_FLASH_ON,
	SENSOR_AF_PRE_FLASH_OFF,
	SENSOR_AF_PRE_FLASH_AE_STABLE,
};

#define VIDIOC_MSM_SENSOR_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 1, struct sensorb_cfg_data)

#define VIDIOC_MSM_SENSOR_RELEASE \
	_IO('V', BASE_VIDIOC_PRIVATE + 2)

#define VIDIOC_MSM_SENSOR_GET_SUBDEV_ID \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 3, uint32_t)

#define VIDIOC_MSM_CSIPHY_IO_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 4, struct csid_cfg_data)

#define VIDIOC_MSM_CSID_IO_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 5, struct csiphy_cfg_data)

#define VIDIOC_MSM_ACTUATOR_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 6, struct msm_actuator_cfg_data)

#define VIDIOC_MSM_FLASH_LED_DATA_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 7, struct msm_camera_led_cfg_t)

#define VIDIOC_MSM_EEPROM_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 8, struct msm_eeprom_cfg_data)

#define VIDIOC_MSM_SENSOR_INIT_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 9, struct sensor_init_cfg_data)

#define VIDIOC_MSM_SENSOR_NATIVE_CMD \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 10, struct ioctl_native_cmd)

#define VIDIOC_MSM_SENSOR_GET_EXIF_DATA \
		_IOWR('V', BASE_VIDIOC_PRIVATE + 11, exif_data_t)
#define MSM_V4L2_PIX_FMT_META v4l2_fourcc('M', 'E', 'T', 'A') /* META */

#endif /* __LINUX_MSM_CAM_SENSOR_H */
