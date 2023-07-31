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
	{ 0xc1514a3b, "free_irq" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xbc477a2, "irq_set_irq_type" },
	{ 0xd6b8e852, "request_threaded_irq" },
	{ 0xfe990052, "gpio_free" },
	{ 0xda2ea9d, "gpiod_direction_input" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x5cbb74c3, "gpiod_to_irq" },
	{ 0xf21f7961, "gpio_to_desc" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0xba6ea6c8, "finish_wait" },
	{ 0x1000e51, "schedule" },
	{ 0x3d72b052, "prepare_to_wait_event" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x7c32d0f0, "printk" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xd70a50c6, "__wake_up" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "351CC635E93EA97D33DC262");
