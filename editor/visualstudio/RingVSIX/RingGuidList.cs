// Guids.cs
// MUST match guids.h
using System;

namespace RingTeam.RingVSIX
{
    static class RingGuidList
    {
        public const string guidRingVSIXPkgString = "23396cdb-691b-4564-8166-b4d494eca6ef";
        public const string guidRingVSIXCmdSetString = "55125363-e1ae-4fb8-89c0-210a235d00ae";
        public const string guidRingVSIXFactoryString = "8E591643-547B-4E1B-B058-098DA11F5402";

        public static readonly Guid guidRingVSIXCmdSet = new Guid(guidRingVSIXCmdSetString);
        public static readonly Guid guidRingVSIXFactory = new Guid(guidRingVSIXFactoryString);
    };
}