// SPDX-License-Identifier: GPL-2.0
/*
 * Support for Intel Camera Imaging ISP subsystem.
 * Copyright (c) 2015, Intel Corporation.
 */

#include "../../include/linux/atomisp.h"
#include "../../include/linux/atomisp_platform.h"
#include "ia_css_version.h"
#include "ia_css_version_data.h"
#include "ia_css_err.h"
#include "sh_css_firmware.h"

int
ia_css_get_version(char *version, int max_size)
{
	char *css_version;

	if (!IS_ISP2401)
		css_version = ISP2400_CSS_VERSION_STRING;
	else
		css_version = ISP2401_CSS_VERSION_STRING;

	if (max_size <= (int)strlen(css_version) + (int)strlen(sh_css_get_fw_version()) + 5)
		return -EINVAL;
	strscpy(version, css_version, max_size);
	strcat(version, "FW:");
	strcat(version, sh_css_get_fw_version());
	strcat(version, "; ");
	return 0;
}
