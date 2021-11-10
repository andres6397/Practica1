#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
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
__used __section("__versions") = {
	{ 0x5200e57f, "module_layout" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x8e917b33, "gpio_to_desc" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0xc5850110, "printk" },
	{ 0x8bc5790d, "gpiod_direction_input" },
	{ 0x45b533d5, "gpiod_direction_output_raw" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x5e2d50e5, "gpiod_set_debounce" },
	{ 0xe7a56280, "gpiod_unexport" },
	{ 0xfe990052, "gpio_free" },
	{ 0xf9179a2e, "gpiod_export" },
	{ 0xd0522fb3, "gpiod_to_irq" },
	{ 0x6d118bcf, "gpiod_set_raw_value" },
	{ 0x9362a711, "gpiod_get_raw_value" },
	{ 0xc1514a3b, "free_irq" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7E1D7F95B83F7C2DA7D6FB8");
