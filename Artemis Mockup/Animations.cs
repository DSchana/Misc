AssetGroup sprite = new AssetGroup("path", SearchOption.AllDirectories);
Animation spriteAnim = new Animation(sprite);

spriteAnim.animate(200);  // Animate sprites with 200ms delay. I'm thinking the time can be represented by the GameTime object
spriteAnim.delayTime = 200;
spriteAnim.animate();  // Animate sprites with preset delay time

spriteAnim.setFrame(3);  // Set next frame to display to the one indicated