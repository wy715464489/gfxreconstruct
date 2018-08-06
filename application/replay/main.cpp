#include "format/file_processor.h"
#include "format/vulkan_replay_consumer.h"
#include "format/vulkan_decoder.h"

int main(int argc, char** argv)
{
    brimstone::format::FileProcessor file_processor;

    if (file_processor.Initialize("D:\\temp\\brimstone_test.bin"))
    {
        brimstone::format::VulkanDecoder decoder;
        brimstone::format::VulkanReplayConsumer ascii_consumer;

        decoder.AddConsumer(&ascii_consumer);

        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();
    }

    return 0;
}
