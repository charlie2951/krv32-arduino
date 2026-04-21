![](https://komarev.com/ghpvc/?username=charlie2951&color=brightgreen)
# KRV32-Arduino
Arduino port of KRV32 RISCV Soft SoC
## Board manager URL
1. Make sure that you have burned the correct MCS file into your board. Download your board firmware `MCS` [from here](https://github.com/charlie2951/krv32/tree/v5.0/mcs).
2. Paste this board manager URL into your Arduino IDE under `File-> Preferences` followed by `Additional board manager url`.
```
https://raw.githubusercontent.com/charlie2951/krv32-arduino/refs/heads/main/package_krv32_index.json
```
3. Now go to `Board manager` and search `krv32`. You will find board named as `krv32 soft RISC-V Soc...`. Install the board. It may take some time to install and download the toolchain.
4. Now, you can explore built-in examples given under `Examples` section, under keyword prefix `krv32_`.
5. To upload a sketch, turn on `BOOT` mode. Arduino IDE will automatically compile and upload sketch. When uploading is done, disable `BOOT` mode and `Reset` the board to start execution.
   
>[!CAUTION]
>**Limited support. Only the provided libraries are supported. External libraries not supported in this version.** 
