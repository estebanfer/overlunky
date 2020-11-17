use byteorder::*;
use std::ptr;
use winapi::um::libloaderapi::GetModuleHandleA;

use crate::search::find_after_bundle;

pub struct Memory {
    pub exe_ptr: usize,
    pub after_bundle: usize,
}

macro_rules! round_up {
    ($i: expr, $div: expr) => {
        (($i + $div - 1) / $div) * $div
    };
}

unsafe fn memory_view<'a>(addr: *mut u8) -> &'a mut [u8] {
    std::slice::from_raw_parts_mut(addr, usize::MAX)
}

pub fn write_mem_prot(addr: usize, payload: &[u8], prot: bool) {
    let mut old_protect: u32 = 0;
    unsafe {
        let page = addr & !0xFFF;
        let size = round_up!((addr + payload.len() - page), 0x1000);
        let page: *mut std::ffi::c_void = std::mem::transmute(page);
        if prot {
            winapi::um::memoryapi::VirtualProtect(
                page,
                size,
                winapi::um::winnt::PAGE_EXECUTE_READWRITE,
                &mut old_protect,
            );
        }
        &mut memory_view(ptr::null_mut())[addr..addr + payload.len()].copy_from_slice(payload);
        if prot {
            winapi::um::memoryapi::VirtualProtect(page, size, old_protect, &mut old_protect);
        }
    }
}

pub fn write_mem(addr: usize, payload: &[u8]) {
    write_mem_prot(addr, payload, false);
}

pub fn read_u8(addr: usize) -> u8 {
    unsafe {
        let mem = memory_view(ptr::null_mut());
        mem[addr]
    }
}

pub fn read_u64(addr: usize) -> usize {
    unsafe {
        let mem = memory_view(ptr::null_mut());
        LE::read_u64(&mem[addr..]) as usize
    }
}

pub fn read_u32(addr: usize) -> u32 {
    unsafe {
        let mem = memory_view(ptr::null_mut());
        LE::read_u32(&mem[addr..]) as u32
    }
}

pub fn read_f32(addr: usize) -> f32 {
    unsafe {
        let mem = memory_view(ptr::null_mut());
        LE::read_f32(&mem[addr..])
    }
}

impl Memory {
    pub unsafe fn new() -> Memory {
        let spel2_ptr = GetModuleHandleA("Spel2.exe\0".as_ptr() as *const i8);
        let exe = memory_view(spel2_ptr as *mut u8);

        // Skipping bundle for faster memory search
        let after_bundle = find_after_bundle(exe);

        Memory {
            exe_ptr: spel2_ptr as usize,
            after_bundle,
        }
    }

    pub fn at_exe(&self, offset: usize) -> usize {
        self.exe_ptr + offset
    }

    pub fn exe(&self) -> &mut [u8] {
        unsafe { memory_view(std::mem::transmute(self.exe_ptr)) }
    }
}
