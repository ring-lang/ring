// Guids.cs
// MUST match guids.h
using System;

namespace RingTeam.RingVSIX
{
    static class GuidList
    {
        public const string guidRingVSIXPkgString = "d04d94b6-a45c-43fb-966e-6d6f0c3786a6";
        public const string guidRingVSIXCmdSetString = "1bed90c3-d03b-47ca-b823-cca6d14c6552";

        public static readonly Guid guidRingVSIXCmdSet = new Guid(guidRingVSIXCmdSetString);
    };
}