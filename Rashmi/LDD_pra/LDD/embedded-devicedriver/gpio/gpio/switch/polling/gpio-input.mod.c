#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9e2dc0be, "module_layout" },
	{ 0xcf56d7c4, "param_ops_int" },
	{ 0x7570fe46, "cdev_del" },
	{ 0xfe990052, "gpio_free" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xca9677f5, "class_destroy" },
	{ 0xa5d2e60, "device_destroy" },
	{ 0xfb0f94f, "cdev_add" },
	{ 0xb3ba9f05, "cdev_init" },
	{ 0xd42ab1b7, "device_create" },
	{ 0xdd978dea, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xda2ea9d, "gpiod_direction_input" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0xf4fa543b, "arm_copy_to_user" },
	{ 0xb70789e, "__might_fault" },
	{ 0x97255bdf, "strlen" },
	{ 0xb81960ca, "snprintf" },
	{ 0xc70dc5ff, "gpiod_get_raw_value" },
	{ 0xf21f7961, "gpio_to_desc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "74397694B332E6CB5B661C8");
