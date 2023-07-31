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
	{ 0x42160169, "flush_workqueue" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xfae03259, "delayed_work_timer_fn" },
	{ 0xbc477a2, "irq_set_irq_type" },
	{ 0xd6b8e852, "request_threaded_irq" },
	{ 0x5cbb74c3, "gpiod_to_irq" },
	{ 0xfe990052, "gpio_free" },
	{ 0xda2ea9d, "gpiod_direction_input" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x34cfdf18, "init_timer_key" },
	{ 0x7ec0fff2, "lockdep_init_map" },
	{ 0xe23ea4f1, "my_queue" },
	{ 0xc4795607, "value" },
	{ 0x2cd3e727, "data_present" },
	{ 0xa778c4b4, "gpio_in" },
	{ 0xd70a50c6, "__wake_up" },
	{ 0xc70dc5ff, "gpiod_get_raw_value" },
	{ 0xf21f7961, "gpio_to_desc" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xe62af1f7, "mod_delayed_work_on" },
	{ 0x7c32d0f0, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=gpio-thread";


MODULE_INFO(srcversion, "0F6CB8E3E4284965338B959");
