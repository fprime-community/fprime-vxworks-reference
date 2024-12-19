

def test_send_command(fprime_test_api):
    """Test that command may be sent and dispatched

    Validate that commands are sent and dispatched by sending a NO_OP and ensuring the response events are received
    within half a second.
    """
    fprime_test_api.send_and_assert_command("ReferenceDeployment.cmdDisp.CMD_NO_OP", max_delay=0.500)
    assert fprime_test_api.get_command_test_history().size() == 1
